#pragma once
#ifndef GHOST
#define GHOST
#include "../../Init.h"

#include "../Players/Player.hpp"

#include "../Rooms/Room.hpp"

#pragma pack(8)
class GhostActivity;

#pragma pack(8)
struct PhotonMessageInfo {
    int64_t timeInt;
    Player* player;
    class PhotonView* photonView;
};

#pragma pack(8)
class GhostAI : public II::MonoBehaviour {
public:
    char space1[0x8];
    enum class GhostState : std::int64_t {
        空闲,
        闲逛,
        猎杀,
        回到鬼房,
        灯,
        门,
        扔东西,
        保险丝,
        现身,
        敲门,
        敲窗,
        汽车警报,
        闪烁,
        闭路电视,
        随机事件,
        鬼能力,
        模特,
        传送物品,
        互动,
        召唤圆圈,
        音乐盒,
        点阵,
        踩盐
    }ghostState;
    char space2[0x8];
    enum class GhostType : std::int32_t {
        魂魄 = 1,
        魅影,
        幻影,
        骚灵,
        女妖,
        巨灵,
        梦魇,
        亡魂,
        暗影,
        恶魔,
        幽灵,
        赤鬼,
        妖怪,
        寒魔,
        御灵,
        鬼婴,
        怨灵,
        孪魂,
        雷魂,
        幻妖,
        拟魂,
        魔洛伊,
        雾影,
        刹耶
    };

    enum class Proof : std::int32_t {
        None,
        EMF-5级,
        通灵盒,
        UltraViolet,
        灵球,
        通灵笔记,
        刺骨寒温,
        点阵投影仪
    };

    struct A : MonoBehaviour {
        char space1[0x8];
        GhostType ghostType;
        GhostType ghostType2;
        II::List<Proof>* proof;
        II::List<Proof>* proof2;
        char space2[0x30];
        Room* room;
    }*ghostInfo;
    char space3[0x18];
    GhostActivity* ghostActivity;
    char space4[0x60];
    float speed;
    char space5[0x8];
    bool hunt;

    static auto InitOnce() -> void;
	inline static GhostAI* ghost{};

    inline static IM::MethodPointer<void, GhostAI*, int> mAppear{};
    inline static IM::MethodPointer<void, GhostAI*> mUnAppear{};
    inline static IM::MethodPointer<void, GhostAI*> mFlashAppear{};
    inline static IM::MethodPointer<void, GhostAI*, bool> mForceFlash{};
    inline static IM::MethodPointer<void, GhostAI*> mCrucifixDelay{};
    inline static IM::MethodPointer<void, GhostAI*> mJinnPowerDistanceCheck{};
    inline static IM::MethodPointer<void, GhostAI*, bool, int, PhotonMessageInfo*> mHunting{};
    inline static IM::MethodPointer<void, GhostAI*> mLookAtNearestPlayer{};
    inline static IM::MethodPointer<void, GhostAI*, Player*> mLookAtPlayer{};
    inline static IM::MethodPointer<void, GhostAI*, float> mDelayTeleportToFavouriteRoom{};
private:
    inline static IM::MethodPointer<void, GhostAI*> mAwake{};
    inline static auto UNITY_CALLING_CONVENTION  HAwake(GhostAI* _this) -> void;
};

#pragma pack(8)
class GhostActivity : public II::MonoBehaviour {
public:
    II::List<void*>* objectsToInteractWith;
    II::List<void*>* space1;
    GhostAI* ghostAi;
    inline static IM::MethodPointer<void, GhostActivity*> mInteract{};
    inline static IM::MethodPointer<bool, GhostActivity*> mInteractWithARandomDoor{};
    inline static IM::MethodPointer<void, GhostActivity*, bool, bool> mInteractWithARandomProp{};
    inline static IM::MethodPointer<void, GhostActivity*, bool> mNormalInteraction{};
    inline static IM::MethodPointer<void*, GhostActivity*, bool> mTwinInteraction{};
    inline static IM::MethodPointer<void, GhostActivity*> mCheckIfNearbyElectronicsAreOn{};
    inline static IM::MethodPointer<void, GhostActivity*> mGhostAbility{};
    inline static IM::MethodPointer<void, GhostActivity*, bool> mForceInteractWithProp{};
private:
};
#endif
