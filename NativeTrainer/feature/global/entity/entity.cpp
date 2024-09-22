#include "pch.h"

using namespace base::math;

namespace feature {
	namespace g_entity {
        Vector3 GetGameplayCamRot() {
            return CAM::GET_GAMEPLAY_CAM_ROT(0);
        }

        void ApplyForce(Entity entityHandle, Vector3 direction, Vector3 offset, int forceType) {
            ENTITY::APPLY_FORCE_TO_ENTITY(entityHandle, forceType, direction.x, direction.y, direction.z, offset.x, offset.y, offset.z, false, false, true, true, false, true);
        }

        void ApplyForce(Entity entityHandle, Vector3 direction, int forceType) {
            ApplyForce(entityHandle, direction, Vector3{ 0, 0, 0 }, forceType);
        }

        void Oscillate(Entity entityHandle, const Vector3& position, float angleFrequency, float dampingRatio) {
            const Vector3 currentPos = ENTITY::GET_ENTITY_COORDS(entityHandle, true, NULL);
            const Vector3 currentVelocity = ENTITY::GET_ENTITY_VELOCITY(entityHandle, NULL);
            Vector3 force = ((position - currentPos) * (angleFrequency * angleFrequency)) - (2.0f * angleFrequency * dampingRatio * currentVelocity) + Vector3{ 0.0f, 0.0f, 0.1f };
            ApplyForce(entityHandle, force, 3);
        }

        void ApplyForceForwardFromWeapon(Entity entityHandle, float force) {
            Vector3 rot = GetGameplayCamRot();
            Vector3 direction = RotationToDirection(&rot);
            ApplyForce(entityHandle, direction * force, 1);
            VEHICLE::SET_VEHICLE_FORWARD_SPEED(entityHandle, force);
        }

        void ApplyForceForwardCam(Entity entityHandle, float force) {
            Vector3 rot = GetGameplayCamRot();
            Vector3 direction = RotationToDirection(&rot);
            ApplyForce(entityHandle, direction * force, 1);
        }

        int GetRay(BOOL* hit, Vector3* endCoords, Vector3* surfaceNormal, Entity* entityHit, bool* isEntityReal) {
            Vector3 rot = GetGameplayCamRot();
            Vector3 camCoords = CAM::GET_GAMEPLAY_CAM_COORD();
            Vector3 farCoords = Add(camCoords, Multiply(RotationToDirection(&rot), 100.f));
            int rayHit = SHAPETEST::_START_SHAPE_TEST_RAY(camCoords.x, camCoords.y, camCoords.z, farCoords.x, farCoords.y, farCoords.z, -1, PLAYER::PLAYER_PED_ID(), 7);
            SHAPETEST::GET_SHAPE_TEST_RESULT(rayHit, hit, endCoords, surfaceNormal, entityHit);
            *isEntityReal = (ENTITY::DOES_ENTITY_EXIST(*entityHit) && (ENTITY::IS_ENTITY_A_PED(*entityHit) || ENTITY::IS_ENTITY_A_VEHICLE(*entityHit) || ENTITY::IS_ENTITY_AN_OBJECT(entityHit)));
            return rayHit;
        }

        //Func may not work - Ported from GTA base
        //Object SetRope(Entity startEntity, Entity endEntity) {
        //    //ROPE::ROPE_LOAD_TEXTURES();
        //    Vector3 startPos = ENTITY::GET_ENTITY_COORDS(startEntity, true);
        //    Vector3 endPos = ENTITY::GET_ENTITY_COORDS(endEntity, true);
        //    float ropeLength = CalculateDistance(&endPos, &startPos);
        //    Object rope = ROPE::ADD_ROPE(startPos.x, startPos.y, startPos.z, 0, 0, 0, ropeLength, 1, 100000, 0.5f, 0.5f, false, true, true, 1.0f, false, 0);
        //    ROPE::ATTACH_ENTITIES_TO_ROPE(rope, startEntity, endEntity, startPos.x, startPos.y, startPos.z, endPos.x, endPos.y, endPos.z, ropeLength + 40.f, 0, 0, NULL, NULL);
        //    ROPE::ACTIVATE_PHYSICS(rope);
        //    return rope;
        //}

        int GetObjectPlayerLookingAt(Entity* entity, bool* isEntityReal) {
            BOOL hit; Vector3 endCoords{ 0,0,0 }; Vector3 surfaceNormal{ 0,0,0 };
            return GetRay(&hit, &endCoords, &surfaceNormal, entity, isEntityReal);
        }

        int GetCoordsPlayerLookingAt(Vector3* endCoords) {
            BOOL hit; Vector3 surfaceNormal{ 0,0,0 }; Entity entity; bool isEntityReal;
            return GetRay(&hit, endCoords, &surfaceNormal, &entity, &isEntityReal);
        }

        void SpawnObject(Object* obj, char* objectHash, Vector3 coords) {
            Hash hash = GAMEPLAY::GET_HASH_KEY(objectHash);
            STREAMING::REQUEST_MODEL(hash, NULL);
            do
            {
                STREAMING::REQUEST_MODEL(hash, NULL);
                WAIT(0);
            } while (!STREAMING::HAS_MODEL_LOADED(hash));
            *obj = OBJECT::CREATE_OBJECT(hash, coords.x, coords.y, coords.z, false, false, false, NULL, NULL);
            ENTITY::FREEZE_ENTITY_POSITION(*obj, true);
            ENTITY::SET_ENTITY_PROOFS(*obj, true, true);
        }

        Vehicle SpawnVehicle(char* vehicleHash, Vector3 pos, float dir) {
            Hash hash = GAMEPLAY::GET_HASH_KEY(vehicleHash);

            if (!STREAMING::IS_MODEL_VALID(hash) &&
                !STREAMING::IS_MODEL_A_VEHICLE(hash))
                return NULL;
            do
            {
                STREAMING::REQUEST_MODEL(hash, NULL);
                WAIT(0);
            } while (!STREAMING::HAS_MODEL_LOADED(hash));


            return VEHICLE::CREATE_VEHICLE(hash, pos.x, pos.y, pos.z, dir, true, true, NULL, NULL);

        }

        void DeletePlayerVehicle(Ped playerPed) {
            if (PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0)) {
                Vehicle V = g_player::GetPlayerVehicle(playerPed);
                if (ENTITY::DOES_ENTITY_EXIST(V)) {
                    ENTITY::DELETE_ENTITY(&V);
                }
            }
        }

        Vector3 GetVehicleCoords() {
            if (PED::IS_PED_IN_ANY_VEHICLE(g_player::GetPlayerPed(), 0)) {
                Vehicle V = g_player::GetPlayerVehicle();
                if (ENTITY::DOES_ENTITY_EXIST(V)) {
                    return ENTITY::GET_ENTITY_COORDS(V, false, NULL);
                }
            }
        }

        void AttachObjects(Entity e1, Entity e2, Vector3 coords) {
            ENTITY::ATTACH_ENTITY_TO_ENTITY(e1, e2, 0, coords.x, coords.y, coords.z, 0, 0, 0, true, true, false, false, 2, true, NULL, NULL);
        }

        void AttachObject(Entity e1, char* objectHash) {
            Object obj;
            SpawnObject(&obj, objectHash, { 0, 0, 0 });
            AttachObjects(obj, e1, { 0, 0, 0 });
        }
	}
}