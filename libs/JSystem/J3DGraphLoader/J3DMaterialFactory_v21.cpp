//
// Generated By: dol2asm
// Translation Unit: J3DMaterialFactory_v21
//

#include "JSystem/J3DGraphLoader/J3DMaterialFactory_v21.h"
#include "JSystem/J3DGraphBase/J3DMaterial.h"
#include "JSystem/JSupport/JSupport.h"
#include "dol2asm.h"

//
// Forward References:
//

extern "C" void __ct__22J3DMaterialFactory_v21FRC20J3DMaterialBlock_v21();
extern "C" void countUniqueMaterials__22J3DMaterialFactory_v21Fv();
extern "C" void countTexGens__22J3DMaterialFactory_v21CFi();
extern "C" void countStages__22J3DMaterialFactory_v21CFi();
extern "C" void create__22J3DMaterialFactory_v21CFP11J3DMaterialiUl();
extern "C" void newMatColor__22J3DMaterialFactory_v21CFii();
extern "C" void newColorChanNum__22J3DMaterialFactory_v21CFi();
extern "C" void newColorChan__22J3DMaterialFactory_v21CFii();
extern "C" void newTexGenNum__22J3DMaterialFactory_v21CFi();
extern "C" void newTexCoord__22J3DMaterialFactory_v21CFii();
extern "C" void newTexMtx__22J3DMaterialFactory_v21CFii();
extern "C" void newCullMode__22J3DMaterialFactory_v21CFi();
extern "C" void newTexNo__22J3DMaterialFactory_v21CFii();
extern "C" void newTevOrder__22J3DMaterialFactory_v21CFii();
extern "C" void newTevColor__22J3DMaterialFactory_v21CFii();
extern "C" void newTevKColor__22J3DMaterialFactory_v21CFii();
extern "C" void newTevStageNum__22J3DMaterialFactory_v21CFi();
extern "C" void newTevStage__22J3DMaterialFactory_v21CFii();
extern "C" void newTevSwapModeTable__22J3DMaterialFactory_v21CFii();
extern "C" void newFog__22J3DMaterialFactory_v21CFi();
extern "C" void newAlphaComp__22J3DMaterialFactory_v21CFi();
extern "C" void newBlend__22J3DMaterialFactory_v21CFi();
extern "C" void newZMode__22J3DMaterialFactory_v21CFi();
extern "C" void newZCompLoc__22J3DMaterialFactory_v21CFi();
extern "C" void newDither__22J3DMaterialFactory_v21CFi();
extern "C" void newNBTScale__22J3DMaterialFactory_v21CFi();
extern "C" void func_80334118(void* _this, void const*, void const*);

//
// External References:
//

extern "C" void __ct__11J3DTevStageFv();
extern "C" void __ct__11J3DTevStageFRC15J3DTevStageInfo();
extern "C" void* __nw__FUl();
extern "C" GXColorS10* func_802F41E8(void const*, void const*);
extern "C" u8* func_802F4260(void const*, void const*);
extern "C" GXColor* func_802F4278(void const*, void const*);
extern "C" GXCullMode* func_802F4290(void const*, void const*);
extern "C" u16* func_802F42C0(void const*, void const*);
extern "C" void createColorBlock__11J3DMaterialFUl();
extern "C" void createTexGenBlock__11J3DMaterialFUl();
extern "C" void createTevBlock__11J3DMaterialFi();
extern "C" void createIndBlock__11J3DMaterialFi();
extern "C" void createPEBlock__11J3DMaterialFUlUl();
extern "C" void initialize__11J3DMaterialFv();
extern "C" void __as__13J3DTexMtxInfoFRC13J3DTexMtxInfo();
extern "C" void __as__10J3DFogInfoFRC10J3DFogInfo();
extern "C" void func_80332C24(void* _this, void const*, void const*);
extern "C" void func_80332C3C(void* _this, void const*, void const*);
extern "C" void func_80332C54(void* _this, void const*, void const*);
extern "C" void func_80332C6C(void* _this, void const*, void const*);
extern "C" void func_80332C84(void* _this, void const*, void const*);
extern "C" void func_80332C9C(void* _this, void const*, void const*);
extern "C" void func_80332CB4(void* _this, void const*, void const*);
extern "C" void func_80332CCC(void* _this, void const*, void const*);
extern "C" void func_80332CE4(void* _this, void const*, void const*);
extern "C" void func_80332CFC(void* _this, void const*, void const*);
extern "C" void func_80332D14(void* _this, void const*, void const*);
extern "C" void func_80332D2C(void* _this, void const*, void const*);
extern "C" void func_80332D5C(void* _this, void const*, void const*);
extern "C" void _savegpr_19();
extern "C" void _savegpr_29();
extern "C" void _restgpr_19();
extern "C" void _restgpr_29();
extern "C" extern void* __vt__11J3DMaterial[12];

//
// Declarations:
//

/* 80332DA4-80332F84 32D6E4 01E0+00 0/0 2/2 0/0 .text
 * __ct__22J3DMaterialFactory_v21FRC20J3DMaterialBlock_v21      */
J3DMaterialFactory_v21::J3DMaterialFactory_v21(J3DMaterialBlock_v21 const& i_block) {
    mMaterialNum = i_block.mMaterialNum;
    mpMaterialInitData = JSUConvertOffsetToPtr<J3DMaterialInitData_v21>(&i_block, i_block.mpMaterialInitData);
    mpMaterialID = JSUConvertOffsetToPtr<u16>(&i_block, i_block.mpMaterialID);
    mpCullMode = JSUConvertOffsetToPtr<GXCullMode>(&i_block, i_block.mpCullMode);
    mpMatColor = JSUConvertOffsetToPtr<GXColor>(&i_block, i_block.mpMatColor);
    mpColorChanNum = JSUConvertOffsetToPtr<u8>(&i_block, i_block.mpColorChanNum);
    mpColorChanInfo = JSUConvertOffsetToPtr<J3DColorChanInfo>(&i_block, i_block.mpColorChanInfo);
    mpTexGenNum = JSUConvertOffsetToPtr<u8>(&i_block, i_block.mpTexGenNum);
    mpTexCoordInfo = JSUConvertOffsetToPtr<J3DTexCoordInfo>(&i_block, i_block.mpTexCoordInfo);
    mpTexCoord2Info = JSUConvertOffsetToPtr<J3DTexCoord2Info>(&i_block, i_block.mpTexCoord2Info);
    mpTexMtxInfo = JSUConvertOffsetToPtr<J3DTexMtxInfo>(&i_block, i_block.mpTexMtxInfo);
    field_0x28 = JSUConvertOffsetToPtr<J3DTexMtxInfo>(&i_block, i_block.field_0x38);
    mpTexNo = JSUConvertOffsetToPtr<u16>(&i_block, i_block.mpTexNo);
    mpTevOrderInfo = JSUConvertOffsetToPtr<J3DTevOrderInfo>(&i_block, i_block.mpTevOrderInfo);
    mpTevColor = JSUConvertOffsetToPtr<GXColorS10>(&i_block, i_block.mpTevColor);
    mpTevKColor = JSUConvertOffsetToPtr<GXColor>(&i_block, i_block.mpTevKColor);
    mpTevStageNum = JSUConvertOffsetToPtr<u8>(&i_block, i_block.mpTevStageNum);
    mpTevStageInfo = JSUConvertOffsetToPtr<J3DTevStageInfo>(&i_block, i_block.mpTevStageInfo);
    mpTevSwapModeInfo = JSUConvertOffsetToPtr<J3DTevSwapModeInfo>(&i_block, i_block.mpTevSwapModeInfo);
    mpTevSwapModeTableInfo = JSUConvertOffsetToPtr<J3DTevSwapModeTableInfo>(&i_block, i_block.mpTevSwapModeTableInfo);
    mpFogInfo = JSUConvertOffsetToPtr<J3DFogInfo>(&i_block, i_block.mpFogInfo);
    mpAlphaCompInfo = JSUConvertOffsetToPtr<J3DAlphaCompInfo>(&i_block, i_block.mpAlphaCompInfo);
    mpBlendInfo = JSUConvertOffsetToPtr<J3DBlendInfo>(&i_block, i_block.mpBlendInfo);
    mpZModeInfo = JSUConvertOffsetToPtr<J3DZModeInfo>(&i_block, i_block.mpZModeInfo);
    mpZCompLoc = JSUConvertOffsetToPtr<u8>(&i_block, i_block.mpZCompLoc);
    mpDither = JSUConvertOffsetToPtr<u8>(&i_block, i_block.mpDither);
    mpNBTScaleInfo = JSUConvertOffsetToPtr<J3DNBTScaleInfo>(&i_block, i_block.mpNBTScaleInfo);
}

/* 80332F84-80332FA8 32D8C4 0024+00 0/0 1/1 0/0 .text
 * countUniqueMaterials__22J3DMaterialFactory_v21Fv             */
u16 J3DMaterialFactory_v21::countUniqueMaterials() {
    u16 i;
    for (i = 0; i < mMaterialNum; i++) {
    }
    return i;
}

/* 80332FA8-80332FE0 32D8E8 0038+00 1/1 0/0 0/0 .text countTexGens__22J3DMaterialFactory_v21CFi */
u32 J3DMaterialFactory_v21::countTexGens(int i_idx) const {
    u8 tex_gen_num_index = mpMaterialInitData[mpMaterialID[i_idx]].mTexGenNumIdx;
    if (tex_gen_num_index != 0xff) {
        return mpTexGenNum[tex_gen_num_index];
    }
    return 0;
}

/* 80332FE0-80333068 32D920 0088+00 1/1 0/0 0/0 .text countStages__22J3DMaterialFactory_v21CFi */
u32 J3DMaterialFactory_v21::countStages(int i_idx) const {
    J3DMaterialInitData_v21* init_data = &mpMaterialInitData[mpMaterialID[i_idx]];
    u32 count1 = 0;
    u32 count2 = 0;
    u8 tev_stage_num_index = init_data->mTevStageNumIdx;
    if (tev_stage_num_index != 0xff) {
        count2 = mpTevStageNum[tev_stage_num_index];
    }
    for (int i = 0; i < 8; i++) {
        if (init_data->mTexNoIdx[i] != 0xffff) {
            count1++;
        }
    }
    if (count2 != count1 && count1 != 0) {
        if (count2 > count1) {
            return count2;
        } else {
            return count1;
        }
    }
    return count2;
}

/* 80333068-803337D8 32D9A8 0770+00 0/0 2/2 0/0 .text
 * create__22J3DMaterialFactory_v21CFP11J3DMaterialiUl          */
#pragma push
#pragma optimization_level 0
#pragma optimizewithasm off
asm J3DMaterial* J3DMaterialFactory_v21::create(J3DMaterial* param_0, int param_1, u32 param_2) const {
    nofralloc
#include "asm/JSystem/J3DGraphLoader/J3DMaterialFactory_v21/create__22J3DMaterialFactory_v21CFP11J3DMaterialiUl.s"
}
#pragma pop

/* 803337D8-80333834 32E118 005C+00 1/1 0/0 0/0 .text newMatColor__22J3DMaterialFactory_v21CFii */
J3DGXColor J3DMaterialFactory_v21::newMatColor(int i_idx, int i_no) const {
    GXColor defaultColor = {0xff,0xff,0xff,0xff};
    J3DGXColor defaultJ3DGXColor = J3DGXColor(defaultColor);
    J3DMaterialInitData_v21* mtl_init_data = &mpMaterialInitData[mpMaterialID[i_idx]];
    if (mtl_init_data->mMatColorIdx[i_no] != 0xffff) {
        return J3DGXColor(mpMatColor[mtl_init_data->mMatColorIdx[i_no]]);
    } 
    return J3DGXColor(defaultJ3DGXColor);
}

/* 80333834-8033386C 32E174 0038+00 1/1 0/0 0/0 .text newColorChanNum__22J3DMaterialFactory_v21CFi
 */
u8 J3DMaterialFactory_v21::newColorChanNum(int i_idx) const {
    u8 color_chan_num_index = mpMaterialInitData[mpMaterialID[i_idx]].mColorChanNumIdx;
    if (color_chan_num_index != 0xff) {
        return mpColorChanNum[color_chan_num_index];
    } else {
        return 0;
    }
}

/* 8033386C-80333A10 32E1AC 01A4+00 1/1 0/0 0/0 .text newColorChan__22J3DMaterialFactory_v21CFii
 */
// J3DColorChan ctor
#ifdef NONMATCHING
J3DColorChan J3DMaterialFactory_v21::newColorChan(int i_idx, int i_no) const {
    J3DMaterialInitData_v21* mtl_init_data = &mpMaterialInitData[mpMaterialID[i_idx]];
    if (mtl_init_data->mColorChanIdx[i_no] != 0xffff) {
        return J3DColorChan(mpColorChanInfo[mtl_init_data->mColorChanIdx[i_no]]);
    } else {
        return J3DColorChan();
    }
}
#else
#pragma push
#pragma optimization_level 0
#pragma optimizewithasm off
asm J3DColorChan J3DMaterialFactory_v21::newColorChan(int param_0, int param_1) const {
    nofralloc
#include "asm/JSystem/J3DGraphLoader/J3DMaterialFactory_v21/newColorChan__22J3DMaterialFactory_v21CFii.s"
}
#pragma pop
#endif

/* 80333A10-80333A48 32E350 0038+00 1/1 0/0 0/0 .text newTexGenNum__22J3DMaterialFactory_v21CFi */
u32 J3DMaterialFactory_v21::newTexGenNum(int i_idx) const {
    u8 tex_gen_num_index = mpMaterialInitData[mpMaterialID[i_idx]].mTexGenNumIdx;
    if (tex_gen_num_index != 0xff) {
        return mpTexGenNum[tex_gen_num_index];
    } else {
        return 0;
    }
}

/* 80333A48-80333AA8 32E388 0060+00 1/1 0/0 0/0 .text newTexCoord__22J3DMaterialFactory_v21CFii */
J3DTexCoord J3DMaterialFactory_v21::newTexCoord(int i_idx, int i_no) const {
    u16 tex_coord_index = mpMaterialInitData[mpMaterialID[i_idx]].mTexCoordIdx[i_no];
    if (tex_coord_index != 0xffff) {
        return J3DTexCoord(mpTexCoordInfo[tex_coord_index]);
    } else {
        return J3DTexCoord();
    }
}

/* 80333AA8-80333B30 32E3E8 0088+00 1/1 0/0 0/0 .text newTexMtx__22J3DMaterialFactory_v21CFii */
J3DTexMtx* J3DMaterialFactory_v21::newTexMtx(int i_idx, int i_no) const {
    J3DTexMtx* tex_mtx = NULL;
    J3DMaterialInitData_v21* mtl_init_data = &mpMaterialInitData[mpMaterialID[i_idx]];
    if (mtl_init_data->mTexMtxIdx[i_no] != 0xffff) {
        tex_mtx = new J3DTexMtx(mpTexMtxInfo[mtl_init_data->mTexMtxIdx[i_no]]);
    }
    return tex_mtx;
}

/* 80333B30-80333B70 32E470 0040+00 1/1 0/0 0/0 .text newCullMode__22J3DMaterialFactory_v21CFi */
u8 J3DMaterialFactory_v21::newCullMode(int i_idx) const {
    u8 cull_mode_index = mpMaterialInitData[mpMaterialID[i_idx]].mCullModeIdx;
    if (cull_mode_index != 0xff) {
        return mpCullMode[cull_mode_index];
    } else {
        return 0xff;
    }
}

/* 80333B70-80333BB8 32E4B0 0048+00 1/1 0/0 0/0 .text newTexNo__22J3DMaterialFactory_v21CFii */
u16 J3DMaterialFactory_v21::newTexNo(int i_idx, int i_no) const {
    u16 tex_no_index = mpMaterialInitData[mpMaterialID[i_idx]].mTexNoIdx[i_no];
    if (tex_no_index != 0xffff) {
        return mpTexNo[tex_no_index];
    } else {
        return 0xffff;
    }
}

/* 80333BB8-80333C04 32E4F8 004C+00 1/1 0/0 0/0 .text newTevOrder__22J3DMaterialFactory_v21CFii */
J3DTevOrder J3DMaterialFactory_v21::newTevOrder(int i_idx, int i_no) const {
    J3DMaterialInitData_v21* mtl_init_data = &mpMaterialInitData[mpMaterialID[i_idx]];
    if (mtl_init_data->mTevOrderIdx[i_no] != 0xffff) {
        return J3DTevOrder(mpTevOrderInfo[mtl_init_data->mTevOrderIdx[i_no]]);
    } else {
        return J3DTevOrder();
    }
}

/* 80333C04-80333C74 32E544 0070+00 1/1 0/0 0/0 .text newTevColor__22J3DMaterialFactory_v21CFii */
J3DGXColorS10 J3DMaterialFactory_v21::newTevColor(int i_idx, int i_no) const {
    GXColorS10 defaultTevColor = {0,0,0,0};
    J3DGXColorS10 dflt = defaultTevColor;
    J3DMaterialInitData_v21* mtl_init_data = &mpMaterialInitData[mpMaterialID[i_idx]];
    if (mtl_init_data->mTevColorIdx[i_no] != 0xffff) {
        return mpTevColor[mtl_init_data->mTevColorIdx[i_no]];
    } else {
        return defaultTevColor;
    }
}

/* 80333C74-80333CD0 32E5B4 005C+00 1/1 0/0 0/0 .text newTevKColor__22J3DMaterialFactory_v21CFii
 */
J3DGXColor J3DMaterialFactory_v21::newTevKColor(int i_idx, int param_1) const {
    GXColor defaultColor = {0xff,0xff,0xff,0xff};
    J3DGXColor defaultJ3DGXColor = J3DGXColor(defaultColor);
    J3DMaterialInitData_v21* mtl_init_data = &mpMaterialInitData[mpMaterialID[i_idx]];
    if (mtl_init_data->mTevKColorIdx[param_1] != 0xffff) {
        return J3DGXColor(mpTevKColor[mtl_init_data->mTevKColorIdx[param_1]]);
    } 
    return J3DGXColor(defaultJ3DGXColor);
}

/* 80333CD0-80333D08 32E610 0038+00 1/1 0/0 0/0 .text newTevStageNum__22J3DMaterialFactory_v21CFi
 */
u8 J3DMaterialFactory_v21::newTevStageNum(int i_idx) const {
    u8 tev_stage_num_index = mpMaterialInitData[mpMaterialID[i_idx]].mTevStageNumIdx;
    if (tev_stage_num_index != 0xff) {
        return mpTevStageNum[tev_stage_num_index];
    } else {
        return 0xff;
    }
}

/* 80333D08-80333D68 32E648 0060+00 1/1 0/0 0/0 .text newTevStage__22J3DMaterialFactory_v21CFii */
J3DTevStage J3DMaterialFactory_v21::newTevStage(int i_idx, int i_no) const {
    u16 tev_stage_index = mpMaterialInitData[mpMaterialID[i_idx]].mTevStageIdx[i_no];
    if (tev_stage_index != 0xffff) {
        return J3DTevStage(mpTevStageInfo[tev_stage_index]);
    } else {
        return J3DTevStage();
    }
}

/* 80333D68-80333E04 32E6A8 009C+00 1/1 0/0 0/0 .text
 * newTevSwapModeTable__22J3DMaterialFactory_v21CFii            */
J3DTevSwapModeTable J3DMaterialFactory_v21::newTevSwapModeTable(int i_idx, int param_1) const {
    J3DMaterialInitData_v21* mtl_init_data = &mpMaterialInitData[mpMaterialID[i_idx]];
    if (mtl_init_data->mTevSwapModeTableIdx[param_1] != 0xffff) {
        return J3DTevSwapModeTable(mpTevSwapModeTableInfo[mtl_init_data->mTevSwapModeTableIdx[param_1]]);
    } 
    return J3DTevSwapModeTable(j3dDefaultTevSwapModeTable);
}

/* 80333E04-80333EE0 32E744 00DC+00 1/1 0/0 0/0 .text            newFog__22J3DMaterialFactory_v21CFi
 */
J3DFog J3DMaterialFactory_v21::newFog(int i_idx) const {
    J3DFog fog;
    u16 fog_index = mpMaterialInitData[mpMaterialID[i_idx]].mFogIdx;
    if (fog_index != 0xffff) {
        fog.setFogInfo(mpFogInfo[fog_index]);
    }
    return fog;
}

/* 80333EE0-80333F60 32E820 0080+00 1/1 0/0 0/0 .text newAlphaComp__22J3DMaterialFactory_v21CFi */
// calcAlphaCmpID issue
#ifdef NONMATCHING
J3DAlphaComp J3DMaterialFactory_v21::newAlphaComp(int i_idx) const {
    J3DMaterialInitData_v21* mtl_init_data = &mpMaterialInitData[mpMaterialID[i_idx]];
    if (mtl_init_data->mAlphaCompIdx != 0xffff) {
        return J3DAlphaComp(mpAlphaCompInfo[mtl_init_data->mAlphaCompIdx]);
    } 
    return J3DAlphaComp(0xffff);
}
#else
#pragma push
#pragma optimization_level 0
#pragma optimizewithasm off
asm J3DAlphaComp J3DMaterialFactory_v21::newAlphaComp(int param_0) const {
    nofralloc
#include "asm/JSystem/J3DGraphLoader/J3DMaterialFactory_v21/newAlphaComp__22J3DMaterialFactory_v21CFi.s"
}
#pragma pop
#endif

/* 80333F60-80333FA4 32E8A0 0044+00 1/1 0/0 0/0 .text newBlend__22J3DMaterialFactory_v21CFi */
J3DBlend J3DMaterialFactory_v21::newBlend(int i_idx) const {
    J3DMaterialInitData_v21* mtl_init_data = &mpMaterialInitData[mpMaterialID[i_idx]];
    if (mtl_init_data->mBlendIdx != 0xffff) {
        return J3DBlend(mpBlendInfo[mtl_init_data->mBlendIdx]);
    } else {
        return J3DBlend(j3dDefaultBlendInfo);
    }
}

/* 80333FA4-80334004 32E8E4 0060+00 1/1 0/0 0/0 .text newZMode__22J3DMaterialFactory_v21CFi */
J3DZMode J3DMaterialFactory_v21::newZMode(int i_idx) const {
    J3DMaterialInitData_v21* mtl_init_data = &mpMaterialInitData[mpMaterialID[i_idx]];
    if (mtl_init_data->mZModeIdx != 0xff) {
        return J3DZMode(mpZModeInfo[mtl_init_data->mZModeIdx]);
    } else {
        return J3DZMode();
    }
}

/* 80334004-8033403C 32E944 0038+00 1/1 0/0 0/0 .text newZCompLoc__22J3DMaterialFactory_v21CFi */
u8 J3DMaterialFactory_v21::newZCompLoc(int i_idx) const {
    J3DMaterialInitData_v21* mtl_init_data = &mpMaterialInitData[mpMaterialID[i_idx]];
    if (mtl_init_data->mZCompLocIdx != 0xff){
        return mpZCompLoc[mtl_init_data->mZCompLocIdx];
    } else {
        return 0;
    }
}

/* 8033403C-80334074 32E97C 0038+00 1/1 0/0 0/0 .text newDither__22J3DMaterialFactory_v21CFi */
u8 J3DMaterialFactory_v21::newDither(int i_idx) const {
    J3DMaterialInitData_v21* mtl_init_data = &mpMaterialInitData[mpMaterialID[i_idx]];
    if (mtl_init_data->mDitherIdx != 0xff){
        return mpDither[mtl_init_data->mDitherIdx];
    } else {
        return 1;
    }
}

/* 80334074-80334118 32E9B4 00A4+00 1/1 0/0 0/0 .text newNBTScale__22J3DMaterialFactory_v21CFi */
J3DNBTScale J3DMaterialFactory_v21::newNBTScale(int i_idx) const {
    J3DNBTScale dflt(j3dDefaultNBTScaleInfo);
    J3DMaterialInitData_v21* mtl_init_data = &mpMaterialInitData[mpMaterialID[i_idx]];
    if (mtl_init_data->mNBTScaleIdx != 0xffff) {
        return J3DNBTScale(mpNBTScaleInfo[mtl_init_data->mNBTScaleIdx]);
    } else {
        return dflt;
    }
}