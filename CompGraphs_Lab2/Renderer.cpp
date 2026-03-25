#include "Renderer.h"
#include <cmath>
#include "MathUtils.h"

Point3D Project(const Point3D& p)
{
    return Point3D(p.x, p.y, 0);
}

    COLORREF GetColor(const Vector3D& normal, const std::vector<Light>& lights)
    {
   float intensity = 0.0f;

    for (const auto& light : lights)
    {
        float dot = normal.Dot(light.direction);

        if (dot > 0)
            intensity += dot;
    }

    if (intensity > 1.0f)
        intensity = 1.0f;

    // базовый цвет шара (можешь поменять)
    int baseR = 180;
    int baseG = 100;
    int baseB = 255;

    float ambient = 0.2f;

    intensity = ambient + (1 - ambient) * intensity;

    int r = (int)(baseR * intensity);
    int g = (int)(baseG * intensity);
    int b = (int)(baseB * intensity);

    return RGB(r, g, b);
    }

void DrawTriangle(HDC hdc, Point3D p1, Point3D p2, Point3D p3)
{
    POINT pts[4];

    pts[0] = { (LONG)p1.x + 400, (LONG)p1.y + 300 };
    pts[1] = { (LONG)p2.x + 400, (LONG)p2.y + 300 };
    pts[2] = { (LONG)p3.x + 400, (LONG)p3.y + 300 };
    pts[3] = pts[0];

    Polygon(hdc, pts, 3);
}

void Renderer::Render(HDC hdc,  Mesh& mesh)
{
    for (auto& face : mesh.faces)
    {

        // вращаем вершины
        Point3D p1 = MathUtils::RotateX(mesh.vertices[face.indices[0]], angleX);
        Point3D p2 = MathUtils::RotateX(mesh.vertices[face.indices[1]], angleX);
        Point3D p3 = MathUtils::RotateX(mesh.vertices[face.indices[2]], angleX);

        p1 = MathUtils::RotateY(p1, angleY);
        p2 = MathUtils::RotateY(p2, angleY);
        p3 = MathUtils::RotateY(p3, angleY);

        // проекция
        p1 = Project(p1);
        p2 = Project(p2);
        p3 = Project(p3);

        // свет
        COLORREF color = GetColor(face.normal, lights);

        HBRUSH brush = CreateSolidBrush(color);
        HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

        DrawTriangle(hdc, p1, p2, p3);

        SelectObject(hdc, oldBrush);
        DeleteObject(brush);
    }
}