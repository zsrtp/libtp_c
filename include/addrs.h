#ifndef LIB_TP_ADDRS
#define LIB_TP_ADDRS

#ifdef GCN_NTSCU
// System
#define tp_memset_addr 0x8026f95c
#define tp_memalign_addr 0x80263228
#define tp_free_addr 0x80263260
#define tp_osReport_addr 0x80006ABC
#define tp_memcpy_addr 0x80003540
#define tp_getLayerNo_addr 0x8002B434
#define tp_getSave_addr 0x800350bc
#define tp_putSave_addr 0x800350f0
#define tp_sprintf_addr 0x803664dc
#define tp_strcpy_addr 0x80368b2c
#define tp_strlen_addr 0x80368be4
#define tp_strcmp_addr 0x80368994

// Math
#define tp_atan_addr 0x8036bca4
#define tp_ceil_addr 0x8036bebc
#define tp_copysign_addr 0x8036c000
#define tp_cos_addr 0x8036c028
#define tp_floor_addr 0x8036c0fc
#define tp_frexp_addr 0x8036c244
#define tp_ldexp_addr 0x8036c2d0
#define tp_modf_addr 0x8036c494
#define tp_sin_addr 0x8036c590
#define tp_tan_addr 0x8036c668
#define tp_acos_addr 0x8036c6e0
#define tp_asin_addr 0x8036c700
#define tp_atan2_addr 0x8036c720
#define tp_exp_addr 0x8036c740
#define tp_fmod_addr 0x8036c760
#define tp_pow_addr 0x8036c780
#define tp_fastSqrt_addr 0x80182a24
#define tp_sqrt_addr 0x8036ca54

// Controller
#define tp_mPadStatus_addr 0x804343F0
#define tp_mPadButton_addr 0x80434420
#define tp_mPadMStick_addr 0x804344E0
#define tp_mPadSStick_addr 0x80434520
#define tp_JUTGamePadRead_addr 0x802e08e4
#define tp_cPadInfo_addr 0x803DD2E8

// TP
#define tp_globalCounters_addr 0x80430CD8
#define tp_zelAudio_addr 0x803DBF4C
#define tp_gameInfo_addr 0x804061C0
#define tp_sConsole_addr 0x80450C90
#define tp_fopScnRq_addr 0x80450CE0
#define tp_titleScreenPtr_addr 0x803A3A38
#define tp_matrixPtr_addr 0x803F1E10
#define tp_rng_addr 0x80451168

// Items
#define tp_clawshot_addr 0x8038E9C0
#define tp_clawshot_checkbg_addr 0x801087b0
#define tp_ironboots_addr 0x8038E7F4
#define tp_spinner_addr 0x8038EA30
#define tp_ball_and_chain_addr 0x8038EA70
#define tp_bottle_addr 0x8038E90C

// Actor
#define tp_actor_addr 0x80450610
#define tp_actor_stopstatus_addr 0x80450CBC

// Draw
#define tp_draw_addr 0x8042EBC8

// Link
#define tp_link_human_frontroll_addr 0x8038D7BC
#define tp_link_human_sidestep_addr 0x8038D864
#define tp_link_human_backjump_addr 0x8038D82C
#define tp_link_human_slide_addr 0x8038D8CC
#define tp_link_human_swim_addr 0x8038ED2C
#define tp_link_wolf_general_addr 0x8038EE28
#define tp_link_wolf_swim_addr 0x8038f8b4

// Inventory
#define tp_execItemGet_addr 0x80097E8C

// Scene
#define tp_setTimePass_addr 0x80024DB0

// GX
#define GXSetBlendMode_addr 0x8035FBF0
#define GXBegin_addr 0x8035C764
#define GXSetVtxAttrFmt_addr 0x8035B5C4
#define GXLoadPosMtxImm_addr 0x8036024C
#define GXSetNumIndStages_addr 0x8035F0D4
#define GXSetTevDirect_addr 0x8035F0F8
#define GXSetAlphaCompare_addr 0x8035F624
#define GXSetZMode_addr 0x8035FC9C
#define GXSetTevOp_addr 0x8035F198
#define GXSetNumChans_addr 0x8035DB30
#define GXSetNumTevStages_addr 0x8035F890
#define GXSetNumTexGens_addr 0x8035BDFC
#define GXSetTevOrder_addr 0x8035F6F4
#define GXSetTevColorIn_addr 0x8035F224
#define GXSetTevAlphaIn_addr 0x8035F268
#define GXSetTevColorOp_addr 0x8035F2AC
#define GXSetTevAlphaOp_addr 0x8035F314
#define GXSetCullMode_addr 0x8035C984
#define GXLoadTexMtxImm_addr 0x80360320
#define GXSetChanCtrl_addr 0x8035DB6C
#define GXSetCurrentMtx_addr 0x803602EC
#define GXSetTexCoordGen2_addr 0x8035BB7C
#define GXSetLineWidth_addr 0x8035C8BC
#define GXClearVtxDesc_addr 0x8035B58C
#define GXSetVtxDesc_addr 0x8035AEB8
#define GXFlush_addr 0x8035becc
#define GXInitTexObj_addr 0x8035DE40
#define GXLoadTexObj_addr 0x8035E414
#define GXInvalidateTexAll_addr 0x8035E664
#define GXSetProjection_addr 0x803600D4
#define GXSetScissor_addr 0x803604D0
#define GXGetScissor_addr 0x80360548
#define wgPipe_addr 0xCC008000

//misc functions (sort later)
#define tp_cDyl_InitAsync_addr 0x80018764
#define tp_fapGm_Execute_addr 0x80018a6c
#define tp_draw_console_addr 0x802e8384
#define tp_PADRead_addr 0x8034eea0
#define tp_setSpecialGravity_addr 0x800bb770
#define tp_checkCastleTownUseItem_addr 0x800c0678
#define tp_query042_addr 0x8024bfec
#define tp_cc_at_check_addr 0x80087c04
#endif

#ifdef GCN_PAL
// System
#define tp_memset_addr 0x8027075c
#define tp_memalign_addr 0x80264028
#define tp_free_addr 0x80264060
#define tp_osReport_addr 0x80006ABC
#define tp_memcpy_addr 0x80003540
#define tp_getLayerNo_addr 0x8002b4dc
#define tp_getSave_addr 0x800351ec
#define tp_putSave_addr 0x80035220
#define tp_sprintf_addr 0x8036730c
#define tp_strcpy_addr 0x8036995c
#define tp_strlen_addr 0x80369a14
#define tp_strcmp_addr 0x803697c4

// Math
#define tp_atan_addr 0x8036cad4
#define tp_ceil_addr 0x8036ccec
#define tp_copysign_addr 0x8036ce30
#define tp_cos_addr 0x8036ce58
#define tp_floor_addr 0x8036cf2c
#define tp_frexp_addr 0x8036d074
#define tp_ldexp_addr 0x8036d100
#define tp_modf_addr 0x8036d2c4
#define tp_sin_addr 0x8036d3c0
#define tp_tan_addr 0x8036d498
#define tp_acos_addr 0x8036d510
#define tp_asin_addr 0x8036d530
#define tp_atan2_addr 0x8036d550
#define tp_exp_addr 0x8036d570
#define tp_fmod_addr 0x8036d590
#define tp_pow_addr 0x8036d5b0
#define tp_fastSqrt_addr 0x80182c30
#define tp_sqrt_addr 0x8036d884

// Controller
#define tp_mPadStatus_addr 0x804363b0
#define tp_mPadButton_addr 0x804363e0
#define tp_mPadMStick_addr 0x804364a0
#define tp_mPadSStick_addr 0x804364e0
#define tp_JUTGamePadRead_addr 0x802e16e4
#define tp_cPadInfo_addr 0x803df288

// TP
#define tp_globalCounters_addr 0x80432c98
#define tp_zelAudio_addr 0x803ddeec
#define tp_gameInfo_addr 0x80408160
#define tp_sConsole_addr 0x80452c50
#define tp_fopScnRq_addr 0x80452ca0
#define tp_titleScreenPtr_addr 0x803a5718
#define tp_matrixPtr_addr 0x803f3db0
#define tp_rng_addr 0x80453130

// Items
#define tp_clawshot_addr 0x803901c0
#define tp_clawshot_checkbg_addr 0x801089bc
#define tp_ironboots_addr 0x8038fff4
#define tp_spinner_addr 0x80390230
#define tp_ball_and_chain_addr 0x80390270
#define tp_bottle_addr 0x8039010c

// Actor
#define tp_actor_addr 0x804525d0
#define tp_actor_stopstatus_addr 0x80452c7c

// Draw
#define tp_draw_addr 0x80430b88

// Link
#define tp_link_human_frontroll_addr 0x8038efbc
#define tp_link_human_sidestep_addr 0x8038f064
#define tp_link_human_backjump_addr 0x8038f02c
#define tp_link_human_slide_addr 0x8038f0cc
#define tp_link_human_swim_addr 0x8039052c
#define tp_link_wolf_general_addr 0x80390628
#define tp_link_wolf_swim_addr 0x803910b4

// Inventory
#define tp_execItemGet_addr 0x80097fbc

// Scene
#define tp_setTimePass_addr 0x80024e58

// GX
#define GXSetBlendMode_addr 0x80360a20
#define GXBegin_addr 0x8035d594
#define GXSetVtxAttrFmt_addr 0x8035c3f4
#define GXLoadPosMtxImm_addr 0x8036107c
#define GXSetNumIndStages_addr 0x8035ff04
#define GXSetTevDirect_addr 0x8035ff28
#define GXSetAlphaCompare_addr 0x80360454
#define GXSetZMode_addr 0x80360acc
#define GXSetTevOp_addr 0x8035ffc8
#define GXSetNumChans_addr 0x8035e960
#define GXSetNumTevStages_addr 0x803606c0
#define GXSetNumTexGens_addr 0x8035cc2c
#define GXSetTevOrder_addr 0x80360524
#define GXSetTevColorIn_addr 0x80360054
#define GXSetTevAlphaIn_addr 0x80360098
#define GXSetTevColorOp_addr 0x803600dc
#define GXSetTevAlphaOp_addr 0x80360144
#define GXSetCullMode_addr 0x8035d7b4
#define GXLoadTexMtxImm_addr 0x80361150
#define GXSetChanCtrl_addr 0x8035e99c
#define GXSetCurrentMtx_addr 0x8036111c
#define GXSetTexCoordGen2_addr 0x8035c9ac
#define GXSetLineWidth_addr 0x8035d6ec
#define GXClearVtxDesc_addr 0x8035c3bc
#define GXSetVtxDesc_addr 0x8035bce8
#define GXFlush_addr 0x8035ccfc
#define GXInitTexObj_addr 0x8035ec70
#define GXLoadTexObj_addr 0x8035f244
#define GXInvalidateTexAll_addr 0x8035f494
#define GXSetProjection_addr 0x80360f04
#define GXSetScissor_addr 0x80361300
#define GXGetScissor_addr 0x80361378
#define wgPipe_addr 0xCC008000

//function hooks (move to correct categories later)
#define tp_cDyl_InitAsync_addr 0x8001880c
#define tp_fapGm_Execute_addr 0x80018b14
#define tp_draw_console_addr 0x802e9184
#define tp_PADRead_addr 0x8034fcd0
#define tp_setSpecialGravity_addr 0x800bb97c
#define tp_checkCastleTownUseItem_addr 0x800c0884
#define tp_query042_addr 0x8024c690
#define tp_cc_at_check_addr 0x80087d34
#endif

#ifdef GCN_NTSCJ
// System
#define tp_memset_addr 0x80271d8c
#define tp_memalign_addr 0x80265658
#define tp_free_addr 0x80265690
#define tp_osReport_addr 0x80006ABC
#define tp_memcpy_addr 0x80003540
#define tp_getLayerNo_addr 0x8002c97c
#define tp_getSave_addr 0x800350bc
#define tp_putSave_addr 0x800350f0
#define tp_sprintf_addr 0x80368978
#define tp_strcpy_addr 0x8036afc8
#define tp_strlen_addr 0x8036b080
#define tp_strcmp_addr 0x8036ae30

// Math
#define tp_atan_addr 0x8036e140
#define tp_ceil_addr 0x8036e358
#define tp_copysign_addr 0x8036e49c
#define tp_cos_addr 0x8036e4c4
#define tp_floor_addr 0x8036e598
#define tp_frexp_addr 0x8036e6e0
#define tp_ldexp_addr 0x8036e76c
#define tp_modf_addr 0x8036e930
#define tp_sin_addr 0x8036ea2c
#define tp_tan_addr 0x8036eb04
#define tp_acos_addr 0x8036eb7c
#define tp_asin_addr 0x8036eb9c
#define tp_atan2_addr 0x8036ebbc
#define tp_exp_addr 0x8036ebdc
#define tp_fmod_addr 0x8036ebfc
#define tp_pow_addr 0x8036ec1c
#define tp_fastSqrt_addr 0x80182a70
#define tp_sqrt_addr 0x8036eef0

// Controller
#define tp_mPadStatus_addr 0x8042e530
#define tp_mPadButton_addr 0x8042e560
#define tp_mPadMStick_addr 0x8042e620
#define tp_mPadSStick_addr 0x8042e660
#define tp_JUTGamePadRead_addr 0x802e2d80
#define tp_cPadInfo_addr 0x803d7428

// TP
#define tp_globalCounters_addr 0x8042ae18
#define tp_zelAudio_addr 0x803d608c
#define tp_gameInfo_addr 0x80400300
#define tp_sConsole_addr 0x8044add0
#define tp_fopScnRq_addr 0x8044ae20
#define tp_titleScreenPtr_addr 0x8039db98
#define tp_matrixPtr_addr 0x803ebf50
#define tp_rng_addr 0x8044b2a8

// Items
#define tp_clawshot_addr 0x80388a40
#define tp_clawshot_checkbg_addr 0x801087e8
#define tp_ironboots_addr 0x80388874
#define tp_spinner_addr 0x80388ab0
#define tp_ball_and_chain_addr 0x80388af0
#define tp_bottle_addr 0x8038898c

// Actor
#define tp_actor_addr 0x8044a750
#define tp_actor_stopstatus_addr 0x8044adfc

// Draw
#define tp_draw_addr 0x80428d08

// Link
#define tp_link_human_frontroll_addr 0x8038783c
#define tp_link_human_sidestep_addr 0x803878e4
#define tp_link_human_backjump_addr 0x803878ac
#define tp_link_human_slide_addr 0x8038794c
#define tp_link_human_swim_addr 0x80388dac
#define tp_link_wolf_general_addr 0x80388ea8
#define tp_link_wolf_swim_addr 0x80389934

// Inventory
#define tp_execItemGet_addr 0x80097ecc

// Scene
#define tp_setTimePass_addr 0x80024db0

// GX
#define GXSetBlendMode_addr 0x8036208c
#define GXBegin_addr 0x8035ec00
#define GXSetVtxAttrFmt_addr 0x8035da60
#define GXLoadPosMtxImm_addr 0x803626e8
#define GXSetNumIndStages_addr 0x80361570
#define GXSetTevDirect_addr 0x80361594
#define GXSetAlphaCompare_addr 0x80361ac0
#define GXSetZMode_addr 0x80362138
#define GXSetTevOp_addr 0x80361634
#define GXSetNumChans_addr 0x8035ffcc
#define GXSetNumTevStages_addr 0x80361d2c
#define GXSetNumTexGens_addr 0x8035e298
#define GXSetTevOrder_addr 0x80361b90
#define GXSetTevColorIn_addr 0x803616c0
#define GXSetTevAlphaIn_addr 0x80361704
#define GXSetTevColorOp_addr 0x80361748
#define GXSetTevAlphaOp_addr 0x803617b0
#define GXSetCullMode_addr 0x8035ee20
#define GXLoadTexMtxImm_addr 0x803627bc
#define GXSetChanCtrl_addr 0x80360008
#define GXSetCurrentMtx_addr 0x80362788
#define GXSetTexCoordGen2_addr 0x8035e018
#define GXSetLineWidth_addr 0x8035ed58
#define GXClearVtxDesc_addr 0x8035da28
#define GXSetVtxDesc_addr 0x8035d354
#define GXFlush_addr 0x8035e368
#define GXInitTexObj_addr 0x803602dc
#define GXLoadTexObj_addr 0x803608b0
#define GXInvalidateTexAll_addr 0x80360b00
#define GXSetProjection_addr 0x80362570
#define GXSetScissor_addr 0x8036296c
#define GXGetScissor_addr 0x803629e4
#define wgPipe_addr 0xCC008000

//function hooks (move to correct categories later)
#define tp_cDyl_InitAsync_addr 0x80018764
#define tp_fapGm_Execute_addr 0x80018a6c
#define tp_draw_console_addr 0x802ea820
#define tp_PADRead_addr 0x8035133c
#define tp_setSpecialGravity_addr 0x800bb7a8
#define tp_checkCastleTownUseItem_addr 0x800c06b0
#define tp_query042_addr 0x8024d954
#define tp_cc_at_check_addr 0x80087c44
#endif

#ifdef WII_NTSCU_10
// System
#define tp_memset_addr 0x8000443c
#define tp_memalign_addr 0x8024df80
#define tp_free_addr 0x8024dfa0
#define tp_osReport_addr 0x800090a8
#define tp_memcpy_addr 0x80004338
#define tp_getLayerNo_addr 0x8002f640
#define tp_getSave_addr 0x8003929c
#define tp_putSave_addr 0x800392cc
#define tp_sprintf_addr 0x803c32e4
#define tp_strcpy_addr 0x803c34f4
#define tp_strlen_addr 0x803bdb38
#define tp_strcmp_addr 0x803c3624

// Math
#define tp_atan_addr 0x803c74e0
#define tp_ceil_addr 0x803c7720
#define tp_copysign_addr 0x803c7860
#define tp_cos_addr 0x803c788c
#define tp_floor_addr 0x803c7960
#define tp_frexp_addr 0x803c7aa4
#define tp_ldexp_addr 0x803c7b2c
#define tp_sin_addr 0x803c7c98
#define tp_tan_addr 0x803c7d70
#define tp_acos_addr 0x803c7de8
#define tp_asin_addr 0x803c7dec
#define tp_atan2_addr 0x803c7df0
#define tp_exp_addr 0x803c7df4
#define tp_fmod_addr 0x803c7df8
#define tp_pow_addr 0x803c7dfc
#define tp_fastSqrt_addr 0x8025ca1c
#define tp_sqrt_addr 0x803c8048

// Controller
#define tp_mPadStatus_addr 0x804c2f08
#define tp_mPadButton_addr 0x804c2f38
#define tp_mPadMStick_addr 0x804c2ff8
#define tp_mPadSStick_addr 0x804c3038
#define tp_mPad_addr 0x8044bb60
#define tp_JUTGamePadRead_addr 0x802f4364
#define tp_cPadInfo_addr 0x8044ba60

// TP
#define tp_globalCounters_addr 0x804becb8
#define tp_zelAudio_addr 0x8044a6ac
#define tp_gameInfo_addr 0x80492928
#define tp_sConsole_addr 0x8053a8e0
#define tp_fopScnRq_addr 0x8053a928
#define tp_titleScreenPtr_addr 0x804813e0
#define tp_matrixPtr_addr 0x8047e368
#define tp_rng_addr 0x8053ae58
#define tp_homeMenuSts_addr 0x8053A968

// Items
#define tp_clawshot_addr 0x803e4b5c
#define tp_clawshot_checkbg_addr 0x800fcdbc
#define tp_ironboots_addr 0x803e4990
#define tp_spinner_addr 0x803e4bcc
#define tp_ball_and_chain_addr 0x803e4c0c
#define tp_bottle_addr 0x803e4aa8

// Actor
#define tp_actor_addr 0x8053a9c8
#define tp_actor_stopstatus_addr 0x8053a90c

// Draw
#define tp_draw_addr 0x804bb5d8

// Link
#define tp_link_human_frontroll_addr 0x803e3958
#define tp_link_human_sidestep_addr 0x803e3a00
#define tp_link_human_backjump_addr 0x803e39c8
#define tp_link_human_slide_addr 0x803e3a68
#define tp_link_human_swim_addr 0x803e4ec8
#define tp_link_wolf_general_addr 0x803e4fc4
#define tp_link_wolf_swim_addr 0x803e5a50

// Inventory
#define tp_execItemGet_addr 0x80091d6c

// Scene
#define tp_setTimePass_addr 0x8002be74

// GX
#define GXSetBlendMode_addr 0x803602cc
#define GXBegin_addr 0x8035d1dc
#define GXSetVtxAttrFmt_addr 0x8035c064
#define GXLoadPosMtxImm_addr 0x803608b0
#define GXSetNumIndStages_addr 0x8035f83c
#define GXSetTevDirect_addr 0x8035f85c
#define GXSetAlphaCompare_addr 0x8035fd38
#define GXSetZMode_addr 0x80360374
#define GXSetTevOp_addr 0x8035f8fc
#define GXSetNumChans_addr 0x8035e4a4
#define GXSetNumTevStages_addr 0x8035ff58
#define GXSetNumTexGens_addr 0x8035c6c0
#define GXSetTevOrder_addr 0x8035fdfc
#define GXSetTevColorIn_addr 0x8035f990
#define GXSetTevAlphaIn_addr 0x8035f9d0
#define GXSetTevColorOp_addr 0x8035fa10
#define GXSetTevAlphaOp_addr 0x8035fa68
#define GXSetCullMode_addr 0x8035d4a4
#define GXLoadTexMtxImm_addr 0x80360978
#define GXSetChanCtrl_addr 0x8035e4c8
#define GXSetCurrentMtx_addr 0x80360958
#define GXSetTexCoordGen2_addr 0x8035c498
#define GXSetLineWidth_addr 0x8035d400
#define GXClearVtxDesc_addr 0x8035c030
#define GXSetVtxDesc_addr 0x8035b9e4
#define GXFlush_addr 0x8035c770
#define GXInitTexObj_addr 0x8035e750
#define GXLoadTexObj_addr 0x8035ec94
#define GXInvalidateTexAll_addr 0x8035ee78
#define GXSetProjection_addr 0x803607c0
#define GXSetScissor_addr 0x80360b08
#define GXGetScissor_addr 0x80360b70
#define wgPipe_addr 0xCC008000

//misc functions (sort later)
#define tp_cDyl_InitAsync_addr 0x8001e300
#define tp_fapGm_Execute_addr 0x8001e6b0
#define tp_draw_console_addr 0x802fb3ac
#define tp_PADRead_addr 0x8037a0d0
#define tp_setSpecialGravity_addr 0x800b2898
#define tp_checkCastleTownUseItem_addr 0x800b6d6c
#define tp_query042_addr 0x80238c6c
#define tp_cc_at_check_addr 0x800846b4
#endif

#endif  // LIB_TP_ADDRS