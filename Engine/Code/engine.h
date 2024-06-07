//
// engine.h: This file contains the types and functions relative to the engine.
//

#pragma once

#include "platform.h"
#include "BufferSupFuncs.h"
#include "ModelLoadingFuncs.h"
#include "Globals.h"

const VertexV3V2 vertices[] = {
    {glm::vec3(-1.0,-1.0,0.0), glm::vec2(0.0,0.0)},
    {glm::vec3(1.0,-1.0,0.0), glm::vec2(1.0,0.0)},
    {glm::vec3(1.0,1.0,0.0), glm::vec2(1.0,1.0)},
    {glm::vec3(-1.0,1.0,0.0), glm::vec2(0.0,1.0)},
};

const u16 indices[] =
{
    0,1,2,
    0,2,3
};

struct App
{
    void ColorAttachment(GLuint& colorAttachmentHandle);
    void DepthAttachment(GLuint& depthAttachmentHandle);
    void UpdateEntityBuffer();

    void ConfigureFrameBuffer(FrameBuffer& aConfigFB);
    void RenderGeometry(const Program& texturedMeshProgram);

    const GLuint CreateTexture(const bool isFloatingPoint = false);

    unsigned int loadCubemap(std::vector<std::string> faces);


    // Loop
    f32  deltaTime;
    bool isRunning;

    // Input
    Input input;

    float yaw = -90.0f;
    float pitch = 0.0f; 
    bool firstMouse = true;

    // Graphics
    char gpuName[64];
    char openGlVersion[64];

    ivec2 displaySize;

    std::vector<Texture>    textures;
    std::vector<Material>   materials;
    std::vector<Mesh>       meshes;
    std::vector<Model>      models;
    std::vector<Program>    programs;

    GLuint renderToBackBufferShader;
    GLuint renderToFrameBufferShader;
    GLuint freamebufferToQuadShader;

    // program indices
    u32 texturedGeometryProgramIdx = 0;
    u32 texturedMeshProgramIdx = 0;

    u32 patricioModel = 0;
    GLuint texturedMeshProgram_uTexture;
    
    // texture indices
    u32 diceTexIdx;
    u32 whiteTexIdx;
    u32 blackTexIdx;
    u32 normalTexIdx;
    u32 magentaTexIdx;

    // Mode
    Mode mode;

    // Embedded geometry (in-editor simple meshes such as
    // a screen filling quad, a cube, a sphere...)
    GLuint embeddedVertices;
    GLuint embeddedElements;

    // Location of the texture uniform in the textured quad shader
    GLuint programUniformTexture;

    // VAO object to link our screen filling quad with our textured quad shader
    GLuint vao;
    GLuint vbo;

    std::string openglDebugInfo;

    GLint maxUniformBufferSize;
    GLint uniformBlockAligment;
    Buffer localUniformBuffer;
    std::vector<Entity> entities;
    std::vector<Light> lights;

    GLuint globalParamsOffset;
    GLuint globalParamsSize;

    FrameBuffer defferredFrameBuffer;

    vec3 target = vec3(0.f, 0.f, 0.f);
    vec3 cameraPosition = vec3(5.0, 5.0, 5.0);
    vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

  
   // Texture *texture = nullptr;
   // bool needsProcessing = false;
   //
   // Texture *enviormentMap = nullptr;
   // Texture *irradianceMap = nullptr;



};
// ---------------------------------------------------------------------------------------
struct EnviroMement {
    Texture* texture = nullptr;

    bool needsProcessing = false;

    // TextureCube* enviromentMap;
    // TextureCube* irradianceMap;

};
// ---------------------------------------------------------------------------------------
void Init(App* app);

void Gui(App* app);

void Update(App* app);

void Render(App* app);

