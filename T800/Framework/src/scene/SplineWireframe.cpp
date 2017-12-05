#include "scene/SplineWireframe.h"
#include "utils/Utils.h"
namespace t800 {
  extern Device*            T8Device;
  extern DeviceContext*     T8DeviceContext;
void SplineWireframe::Create()
{
  char *vsSourceP;
  char *fsSourceP;
  if (g_pBaseDriver->m_currentAPI == GRAPHICS_API::OPENGL) {
    vsSourceP = file2string("Shaders/VS_W.glsl");
    fsSourceP = file2string("Shaders/FS_W.glsl");
  }
  else {
    vsSourceP = file2string("Shaders/VS_W.hlsl");
    fsSourceP = file2string("Shaders/FS_W.hlsl");
  }


  std::string vstr = std::string(vsSourceP);
  std::string fstr = std::string(fsSourceP);

  free(vsSourceP);
  free(fsSourceP);

  shaderID = g_pBaseDriver->CreateShader(vstr, fstr, T8_NO_SIGNATURE);
  s = g_pBaseDriver->GetShaderIdx(shaderID);


  m_spline.m_points.push_back(SplinePoint(0,  10, 0));
  m_spline.m_points.back().m_velocity = 5.0f;
  m_spline.m_points.push_back(SplinePoint(10, 10, 10));
  m_spline.m_points.back().m_velocity = 8.0f;
  m_spline.m_points.push_back(SplinePoint(85, 50, 150));
  m_spline.m_points.back().m_velocity = 15.0f;
  m_spline.m_points.push_back(SplinePoint(250, 10, 100));
  m_spline.m_points.back().m_velocity = 25.0f;
  m_spline.m_points.push_back(SplinePoint(500, 10, 250));
  m_spline.m_points.back().m_velocity = 10.0f;
  m_spline.m_points.push_back(SplinePoint(600, 10, 300));
  m_spline.m_points.back().m_velocity = 5.0f;
  m_spline.m_looped = false;
  m_spline.Init();

  float length = m_spline.m_totalLength * POINMTS_PER_UNIT;
  for (float i = 0; i < (float)m_spline.m_points.size() - 3.0f; i+= m_spline.STEP_SIZE) {
    XVECTOR3 v = m_spline.GetPoint(i);
    vertices.push_back(Vert{ v.x,v.y,v.z,1.0f });
  }
  for (int i = 0; i < vertices.size(); i++) {
    indices.push_back(i);
  }

  t800::BufferDesc bdesc;
  bdesc.byteWidth = sizeof(CBuffer);
  bdesc.usage = T8_BUFFER_USAGE::DEFAULT;
  CB = (t800::ConstantBuffer*)T8Device->CreateBuffer(T8_BUFFER_TYPE::CONSTANT, bdesc);

  bdesc.byteWidth = sizeof(Vert) * vertices.size();
  bdesc.usage = T8_BUFFER_USAGE::DEFAULT;
  VB = (t800::VertexBuffer*)T8Device->CreateBuffer(T8_BUFFER_TYPE::VERTEX, bdesc, &vertices[0]);


  bdesc.byteWidth = indices.size() * sizeof(unsigned short);
  bdesc.usage = T8_BUFFER_USAGE::DEFAULT;
  IB = (t800::IndexBuffer*)T8Device->CreateBuffer(T8_BUFFER_TYPE::INDEX, bdesc, &indices[0]);
  
}
void SplineWireframe::Transform(float * t)
{
}
void SplineWireframe::Draw(float * t, float * vp)
{

  Camera *pActualCamera = pScProp->pCameras[0];
  constantBuff.WVP = pActualCamera->VP;
  IB->Set(*T8DeviceContext, 0, T8_IB_FORMAR::R16);
  VB->Set(*T8DeviceContext,sizeof(Vert),0);
  s->Set(*T8DeviceContext);
  CB->UpdateFromBuffer(*T8DeviceContext, &constantBuff.WVP[0]);
  CB->Set(*T8DeviceContext);
  T8DeviceContext->SetPrimitiveTopology(T8_TOPOLOGY::LINE_STRIP);
  T8DeviceContext->DrawIndexed(vertices.size(), 0, 0);
}
void SplineWireframe::Destroy()
{
}
}