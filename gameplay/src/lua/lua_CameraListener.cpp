// Autogenerated by gameplay-luagen
#include "Base.h"
#include "ScriptController.h"
#include "lua_CameraListener.h"
#include "Animation.h"
#include "AnimationTarget.h"
#include "AudioListener.h"
#include "Base.h"
#include "Camera.h"
#include "Game.h"
#include "MaterialParameter.h"
#include "Node.h"
#include "PhysicsController.h"
#include "Ref.h"
#include "ScriptController.h"
#include "ScriptTarget.h"
#include "TerrainPatch.h"
#include "Transform.h"
#include "AudioListener.h"
#include "TerrainPatch.h"

namespace gameplay
{

extern void luaGlobal_Register_Conversion_Function(const char* className, void*(*func)(void*, const char*));

static Camera::Listener* getInstance(lua_State* state)
{
    void* userdata = luaL_checkudata(state, 1, "CameraListener");
    luaL_argcheck(state, userdata != NULL, 1, "'CameraListener' expected.");
    return (Camera::Listener*)((gameplay::ScriptUtil::LuaObject*)userdata)->instance;
}

static int lua_CameraListener__gc(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                void* userdata = luaL_checkudata(state, 1, "CameraListener");
                luaL_argcheck(state, userdata != NULL, 1, "'CameraListener' expected.");
                gameplay::ScriptUtil::LuaObject* object = (gameplay::ScriptUtil::LuaObject*)userdata;
                if (object->owns)
                {
                    Camera::Listener* instance = (Camera::Listener*)object->instance;
                    SAFE_DELETE(instance);
                }
                
                return 0;
            }

            lua_pushstring(state, "lua_CameraListener__gc - Failed to match the given parameters to a valid function signature.");
            lua_error(state);
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

static int lua_CameraListener_cameraChanged(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TTABLE || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                bool param1Valid;
                gameplay::ScriptUtil::LuaArray<Camera> param1 = gameplay::ScriptUtil::getObjectPointer<Camera>(2, "Camera", false, &param1Valid);
                if (!param1Valid)
                {
                    lua_pushstring(state, "Failed to convert parameter 1 to type 'Camera'.");
                    lua_error(state);
                }

                Camera::Listener* instance = getInstance(state);
                instance->cameraChanged(param1);
                
                return 0;
            }

            lua_pushstring(state, "lua_CameraListener_cameraChanged - Failed to match the given parameters to a valid function signature.");
            lua_error(state);
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

// Provides support for conversion to all known relative types of Camera::Listener
static void* __convertTo(void* ptr, const char* typeName)
{
    Camera::Listener* ptrObject = reinterpret_cast<Camera::Listener*>(ptr);

    if (strcmp(typeName, "AudioListener") == 0)
    {
        return reinterpret_cast<void*>(static_cast<AudioListener*>(ptrObject));
    }
    else if (strcmp(typeName, "TerrainPatch") == 0)
    {
        return reinterpret_cast<void*>(static_cast<TerrainPatch*>(ptrObject));
    }

    // No conversion available for 'typeName'
    return NULL;
}

static int lua_CameraListener_to(lua_State* state)
{
    // There should be only a single parameter (this instance)
    if (lua_gettop(state) != 2 || lua_type(state, 1) != LUA_TUSERDATA || lua_type(state, 2) != LUA_TSTRING)
    {
        lua_pushstring(state, "lua_CameraListener_to - Invalid number of parameters (expected 2).");
        lua_error(state);
        return 0;
    }

    Camera::Listener* instance = getInstance(state);
    const char* typeName = gameplay::ScriptUtil::getString(2, false);
    void* result = __convertTo((void*)instance, typeName);

    if (result)
    {
        gameplay::ScriptUtil::LuaObject* object = (gameplay::ScriptUtil::LuaObject*)lua_newuserdata(state, sizeof(gameplay::ScriptUtil::LuaObject));
        object->instance = (void*)result;
        object->owns = false;
        luaL_getmetatable(state, typeName);
        lua_setmetatable(state, -2);
    }
    else
    {
        lua_pushnil(state);
    }

    return 1;
}

void luaRegister_CameraListener()
{
    const luaL_Reg lua_members[] = 
    {
        {"cameraChanged", lua_CameraListener_cameraChanged},
        {"to", lua_CameraListener_to},
        {NULL, NULL}
    };
    const luaL_Reg* lua_statics = NULL;
    std::vector<std::string> scopePath;
    scopePath.push_back("Camera");

    gameplay::ScriptUtil::registerClass("CameraListener", lua_members, NULL, lua_CameraListener__gc, lua_statics, scopePath);

    luaGlobal_Register_Conversion_Function("CameraListener", __convertTo);
}

}