#ifndef JPAPARTICLE_H
#define JPAPARTICLE_H

#include <stdint.h>

class JPABaseParticle;
struct _GXTexMapID {};

struct JPABaseEmitter {};

class JPAParticleCallBack {
public:
    virtual void draw(JPABaseEmitter*, JPABaseParticle*);
};

#endif /* JPAPARTICLE_H */
