#ifndef JAISOUND_H
#define JAISOUND_H

#include "../JGeometry.h"
#include <cstddef>

class JAISoundID {
public:
    operator uint32_t() const { return this->mId; }

    JAISoundID(uint32_t pId) : mId(pId) {}

    JAISoundID(JAISoundID const& other);

private:
    uint32_t mId;
};

struct JASSoundParams {};

struct JAISoundParams {
    float field_0x0;
    float field_0x4;
    float field_0x8;
    float field_0xc;
    float field_0x10;
    float field_0x14;
    float field_0x18;
    float field_0x1c;
};

struct JASTrack {
};

class JAISoundHandle;
class JAIAudible;
class JAIAudience;
class JAISound {
public:
    JAISoundID getID() const { return JAISoundID((uint32_t)this->sound_id); }
    uint32_t getUserData() const { return user_data; }

    // TODO: do proper struct later
    void* __vt;
    struct JAISoundHandle* handle;
    struct JAIAudible* audible;
    struct JAIAudience* audience;
    int32_t field_0xc;
    int32_t num_prepare_steps;
    struct JAISoundID sound_id;
    uint8_t field_0x18;
    uint8_t field_0x19;
    uint8_t field_0x1a;
    uint8_t field_0x1b;
    uint32_t user_data;
    float field_0x20;
    float field_0x24;
    float field_0x28;
    int32_t field_0x2c;
    int32_t audience_priority;
    int32_t field_0x34;
    struct JAISoundParams params;
    uint8_t field_0x58;
    uint8_t field_0x59;
    uint8_t field_0x5a;
    uint8_t field_0x5b;
    uint8_t field_0x5c;
    uint8_t field_0x5d;
    uint8_t field_0x5e;
    uint8_t field_0x5f;
    uint8_t field_0x60;
    uint8_t field_0x61;
    uint8_t field_0x62;
    uint8_t field_0x63;
    uint8_t field_0x64;
    uint8_t field_0x65;
    uint8_t field_0x66;
    uint8_t field_0x67;
    uint8_t field_0x68;
    uint8_t field_0x69;
    uint8_t field_0x6a;
    uint8_t field_0x6b;
    uint8_t field_0x6c;
    uint8_t field_0x6d;
    uint8_t field_0x6e;
    uint8_t field_0x6f;
    uint8_t field_0x70;
    uint8_t field_0x71;
    uint8_t field_0x72;
    uint8_t field_0x73;
    uint8_t field_0x74;
    uint8_t field_0x75;
    uint8_t field_0x76;
    uint8_t field_0x77;
    uint8_t field_0x78;
    uint8_t field_0x79;
    uint8_t field_0x7a;
    uint8_t field_0x7b;
    uint8_t field_0x7c;
    uint8_t field_0x7d;
    uint8_t field_0x7e;
    uint8_t field_0x7f;
    uint8_t field_0x80;
    uint8_t field_0x81;
    uint8_t field_0x82;
    uint8_t field_0x83;
    uint8_t field_0x84;
    uint8_t field_0x85;
    uint8_t field_0x86;
    uint8_t field_0x87;
    uint8_t field_0x88;
    uint8_t field_0x89;
    uint8_t field_0x8a;
    uint8_t field_0x8b;
    uint8_t field_0x8c;
    uint8_t field_0x8d;
    uint8_t field_0x8e;
    uint8_t field_0x8f;
    uint8_t field_0x90;
    uint8_t field_0x91;
    uint8_t field_0x92;
    uint8_t field_0x93;
};

class JAISoundHandle {
public:
    JAISoundHandle();
    ~JAISoundHandle();

    bool isSoundAttached() const { return mSound != NULL; }

    JAISound* operator->() const {
        //JUT_ASSERT(mSound != NULL);
        return mSound;
    }

    operator bool() const { return isSoundAttached(); }

private:
    JAISound* mSound;
};

#endif /* JAISOUND_H */
