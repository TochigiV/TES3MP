# local files
set(GAME
    main.cpp
    engine.cpp

    ${CMAKE_SOURCE_DIR}/files/tes3mp/tes3mp.rc
    ${CMAKE_SOURCE_DIR}/files/tes3mp/tes3mp.exe.manifest
)

if (ANDROID)
    set(GAME ${GAME} android_main.cpp)
endif()

set(GAME_HEADER
    engine.hpp
)

source_group(game FILES ${GAME} ${GAME_HEADER})

add_openmw_dir (mwrender
    actors objects renderingmanager animation rotatecontroller sky npcanimation vismask
    creatureanimation effectmanager util renderinginterface pathgrid rendermode weaponanimation screenshotmanager
    bulletdebugdraw globalmap characterpreview camera viewovershoulder localmap water terrainstorage ripplesimulation
    renderbin actoranimation landmanager navmesh actorspaths recastmesh fogmanager objectpaging groundcover
    )

add_openmw_dir (mwinput
    actions actionmanager bindingsmanager controllermanager controlswitch
    inputmanagerimp mousemanager keyboardmanager sdlmappings sensormanager
    )

add_openmw_dir (mwgui
    layout textinput widgets race class birth review windowmanagerimp console dialogue
    windowbase statswindow messagebox journalwindow charactercreation
    mapwindow windowpinnablebase tooltips scrollwindow bookwindow resourceskin
    formatting inventorywindow container hud countdialog tradewindow settingswindow
    confirmationdialog alchemywindow referenceinterface spellwindow mainmenu quickkeysmenu
    itemselection spellbuyingwindow loadingscreen levelupdialog waitdialog spellcreationdialog
    enchantingdialog trainingwindow travelwindow exposedwindow cursor spellicons
    merchantrepair repair soulgemdialog companionwindow bookpage journalviewmodel journalbooks
    itemmodel containeritemmodel inventoryitemmodel sortfilteritemmodel itemview
    tradeitemmodel companionitemmodel pickpocketitemmodel controllers savegamedialog
    recharge mode videowidget backgroundimage itemwidget screenfader debugwindow spellmodel spellview
    draganddrop timeadvancer jailscreen itemchargeview keyboardnavigation textcolours statswatcher
    )

add_openmw_dir (mwdialogue
    dialoguemanagerimp journalimp journalentry quest topic filter selectwrapper hypertextparser keywordsearch scripttest
    )

add_openmw_dir (mwscript
    locals scriptmanagerimp compilercontext interpretercontext cellextensions miscextensions
    guiextensions soundextensions skyextensions statsextensions containerextensions
    aiextensions controlextensions extensions globalscripts ref dialogueextensions
    animationextensions transformationextensions consoleextensions userextensions
    )

add_openmw_dir (mwsound
    soundmanagerimp openal_output ffmpeg_decoder sound sound_buffer sound_decoder sound_output
    loudness movieaudiofactory alext efx efx-presets regionsoundselector watersoundupdater volumesettings
    )

add_openmw_dir (mwworld
    refdata worldimp scene globals class action nullaction actionteleport
    containerstore actiontalk actiontake manualref player cellvisitors failedaction
    cells localscripts customdata inventorystore ptr actionopen actionread actionharvest
    actionequip timestamp actionalchemy cellstore actionapply actioneat
    store esmstore recordcmp fallback actionrepair actionsoulgem livecellref actiondoor
    contentloader esmloader actiontrap cellreflist cellref weather projectilemanager
    cellpreloader datetimemanager
    )

add_openmw_dir (mwphysics
    physicssystem trace collisiontype actor convert object heightfield closestnotmerayresultcallback
    contacttestresultcallback deepestnotmecontacttestresultcallback stepper movementsolver projectile
    actorconvexcallback raycasting mtphysics contacttestwrapper projectileconvexcallback
    )

add_openmw_dir (mwclass
    classes activator creature npc weapon armor potion apparatus book clothing container door
    ingredient creaturelevlist itemlevlist light lockpick misc probe repair static actor bodypart
    )

add_openmw_dir (mwmechanics
    mechanicsmanagerimp stat creaturestats magiceffects movement actorutil spelllist
    drawstate spells activespells npcstats aipackage aisequence aipursue alchemy aiwander aitravel aifollow aiavoiddoor aibreathe
    aicast aiescort aiface aiactivate aicombat recharge repair enchanting pathfinding pathgrid security spellcasting spellresistance
    disease pickpocket levelledlist combat steering obstacle autocalcspell difficultyscaling aicombataction actor summoning
    character actors objects aistate trading weaponpriority spellpriority weapontype spellutil tickableeffects
    spellabsorption linkedeffects
    )

add_openmw_dir (mwstate
    statemanagerimp charactermanager character quicksavemanager
    )

add_openmw_dir (mwbase
    environment world scriptmanager dialoguemanager journal soundmanager mechanicsmanager
    inputmanager windowmanager statemanager
    )

add_openmw_dir (mwmp Main Networking LocalSystem LocalPlayer DedicatedPlayer PlayerList LocalActor DedicatedActor ActorList
    ObjectList Worldstate Cell CellController GUIController MechanicsHelper RecordHelper ScriptController
    )

add_openmw_dir (mwmp/GUI GUIChat GUILogin PlayerMarkerCollection GUIDialogList TextInputDialog
    )

add_openmw_dir(mwmp/processors BaseClientPacketProcessor SystemProcessor PlayerProcessor ObjectProcessor ActorProcessor
    WorldstateProcessor ProcessorInitializer
    )

add_openmw_dir (mwmp/processors/system ProcessorSystemHandshake
    )

add_openmw_dir (mwmp/processors/actor ProcessorActorAI ProcessorActorAnimFlags ProcessorActorAnimPlay ProcessorActorAttack
    ProcessorActorAuthority ProcessorActorCast ProcessorActorCellChange ProcessorActorDeath ProcessorActorEquipment
    ProcessorActorList ProcessorActorPosition ProcessorActorSpeech ProcessorActorSpellsActive ProcessorActorStatsDynamic
    ProcessorActorTest
    )

add_openmw_dir (mwmp/processors/player ProcessorChatMessage ProcessorGUIMessageBox ProcessorUserDisconnected
    ProcessorUserMyID ProcessorGameSettings ProcessorPlayerAlly ProcessorPlayerAnimFlags ProcessorPlayerAnimPlay
    ProcessorPlayerAttack ProcessorPlayerAttribute ProcessorPlayerBaseInfo ProcessorPlayerBehavior ProcessorPlayerBook
    ProcessorPlayerBounty ProcessorPlayerCast ProcessorPlayerCellChange ProcessorPlayerCellState ProcessorPlayerCharClass
    ProcessorPlayerCharGen ProcessorPlayerCooldowns ProcessorPlayerDeath ProcessorPlayerDisposition ProcessorPlayerEquipment
    ProcessorPlayerFaction ProcessorPlayerInput ProcessorPlayerInventory ProcessorPlayerItemUse ProcessorPlayerJail
    ProcessorPlayerJournal ProcessorPlayerLevel ProcessorPlayerMiscellaneous ProcessorPlayerMomentum ProcessorPlayerPosition 
    ProcessorPlayerQuickKeys ProcessorPlayerReputation ProcessorPlayerResurrect ProcessorPlayerShapeshift
    ProcessorPlayerSkill ProcessorPlayerSpeech ProcessorPlayerSpellbook ProcessorPlayerSpellsActive
    ProcessorPlayerStatsDynamic ProcessorPlayerTopic
    )

add_openmw_dir (mwmp/processors/object BaseObjectProcessor

    ProcessorConsoleCommand ProcessorContainer ProcessorDoorDestination ProcessorDoorState ProcessorMusicPlay
    ProcessorVideoPlay

    ProcessorObjectActivate ProcessorObjectAnimPlay ProcessorObjectAttach ProcessorObjectDelete
    ProcessorObjectDialogueChoice ProcessorObjectHit ProcessorObjectLock ProcessorObjectMove ProcessorObjectPlace
    ProcessorObjectRestock ProcessorObjectRotate ProcessorObjectScale ProcessorObjectSound ProcessorObjectSpawn
    ProcessorObjectState ProcessorObjectTrap ProcessorClientScriptLocal ProcessorScriptMemberShort
    ProcessorObjectMiscellaneous
    )

add_openmw_dir (mwmp/processors/worldstate ProcessorCellReset ProcessorClientScriptGlobal ProcessorClientScriptSettings
    ProcessorRecordDynamic ProcessorWorldCollisionOverride ProcessorWorldDestinationOverride ProcessorWorldKillCount
    ProcessorWorldMap ProcessorWorldRegionAuthority ProcessorWorldTime ProcessorWorldWeather
    )

# Main executable

if (NOT ANDROID)
    openmw_add_executable(tes3mp
        ${OPENMW_FILES}
        ${GAME} ${GAME_HEADER}
        ${APPLE_BUNDLE_RESOURCES}
    )
else ()
    add_library(tes3mp
        SHARED
        ${OPENMW_FILES}
        ${GAME} ${GAME_HEADER}
    )
endif ()

# Sound stuff - here so CMake doesn't stupidly recompile EVERYTHING
# when we change the backend.
include_directories(
    ${FFmpeg_INCLUDE_DIRS}
)

target_link_libraries(tes3mp
    # CMake's built-in OSG finder does not use pkgconfig, so we have to
    # manually ensure the order is correct for inter-library dependencies.
    # This only makes a difference with `-DOPENMW_USE_SYSTEM_OSG=ON -DOSG_STATIC=ON`.
    # https://gitlab.kitware.com/cmake/cmake/-/issues/21701
    ${OSGPARTICLE_LIBRARIES}
    ${OSGVIEWER_LIBRARIES}
    ${OSGGA_LIBRARIES}
    ${OSGSHADOW_LIBRARIES}
    ${OSGDB_LIBRARIES}
    ${OSGUTIL_LIBRARIES}
    ${OSG_LIBRARIES}

    ${Boost_SYSTEM_LIBRARY}
    ${Boost_THREAD_LIBRARY}
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_PROGRAM_OPTIONS_LIBRARY}
    ${OPENAL_LIBRARY}
    ${FFmpeg_LIBRARIES}
    ${MyGUI_LIBRARIES}
    ${SDL2_LIBRARY}
    ${RecastNavigation_LIBRARIES}
    "osg-ffmpeg-videoplayer"
    "oics"
    components
    ${RakNet_LIBRARY}
)

if(OSG_STATIC)
    unset(_osg_plugins_static_files)
    add_library(openmw_osg_plugins INTERFACE)
    foreach(_plugin ${USED_OSG_PLUGINS})
        string(TOUPPER ${_plugin} _plugin_uc)
        if(OPENMW_USE_SYSTEM_OSG)
            list(APPEND _osg_plugins_static_files ${${_plugin_uc}_LIBRARY})
        else()
            list(APPEND _osg_plugins_static_files $<TARGET_FILE:${${_plugin_uc}_LIBRARY}>)
            target_link_libraries(openmw_osg_plugins INTERFACE $<TARGET_PROPERTY:${${_plugin_uc}_LIBRARY},LINK_LIBRARIES>)
            add_dependencies(openmw_osg_plugins ${${_plugin_uc}_LIBRARY})
        endif()
    endforeach()
    # We use --whole-archive because OSG plugins use registration.
    get_whole_archive_options(_opts ${_osg_plugins_static_files})
    target_link_options(openmw_osg_plugins INTERFACE ${_opts})
    target_link_libraries(tes3mp openmw_osg_plugins)

    if(OPENMW_USE_SYSTEM_OSG)
        # OSG plugin pkgconfig files are missing these dependencies.
        # https://github.com/openscenegraph/OpenSceneGraph/issues/1052
        target_link_libraries(tes3mp freetype jpeg png)
    endif()
endif(OSG_STATIC)

if (ANDROID)
    target_link_libraries(tes3mp EGL android log z)
endif (ANDROID)

if (USE_SYSTEM_TINYXML)
    target_link_libraries(tes3mp ${TinyXML_LIBRARIES})
endif()

if (NOT UNIX)
target_link_libraries(tes3mp ${SDL2MAIN_LIBRARY})
endif()

# Fix for not visible pthreads functions for linker with glibc 2.15
if (UNIX AND NOT APPLE)
target_link_libraries(tes3mp ${CMAKE_THREAD_LIBS_INIT})
endif()

if(APPLE)
    set(BUNDLE_RESOURCES_DIR "${APP_BUNDLE_DIR}/Contents/Resources")

    set(OPENMW_MYGUI_FILES_ROOT ${BUNDLE_RESOURCES_DIR})
    set(OPENMW_SHADERS_ROOT ${BUNDLE_RESOURCES_DIR})

    add_subdirectory(../../files/ ${CMAKE_CURRENT_BINARY_DIR}/files)

    configure_file("${OpenMW_BINARY_DIR}/defaults.bin" ${BUNDLE_RESOURCES_DIR} COPYONLY)
    configure_file("${OpenMW_BINARY_DIR}/openmw.cfg" ${BUNDLE_RESOURCES_DIR} COPYONLY)
    configure_file("${OpenMW_BINARY_DIR}/gamecontrollerdb.txt" ${BUNDLE_RESOURCES_DIR} COPYONLY)

    configure_file("${OpenMW_BINARY_DIR}/tes3mp-client-default.cfg" ${BUNDLE_RESOURCES_DIR} COPYONLY)

    add_custom_command(TARGET tes3mp
        POST_BUILD
        COMMAND cp "${OpenMW_BINARY_DIR}/resources/version" "${BUNDLE_RESOURCES_DIR}/resources")
    
    find_library(COCOA_FRAMEWORK Cocoa)
    find_library(IOKIT_FRAMEWORK IOKit)
    target_link_libraries(tes3mp ${COCOA_FRAMEWORK} ${IOKIT_FRAMEWORK})

    if (FFmpeg_FOUND)
        find_library(COREVIDEO_FRAMEWORK CoreVideo)
        find_library(VDA_FRAMEWORK VideoDecodeAcceleration)
        target_link_libraries(tes3mp z ${COREVIDEO_FRAMEWORK} ${VDA_FRAMEWORK})
    endif()
endif(APPLE)

if (BUILD_WITH_CODE_COVERAGE)
  add_definitions (--coverage)
  target_link_libraries(tes3mp gcov)
endif()

if (MSVC)
    # Debug version needs increased number of sections beyond 2^16
    if (CMAKE_CL_64)
        set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /bigobj")
    endif (CMAKE_CL_64)
endif (MSVC)

if (WIN32)
    INSTALL(TARGETS tes3mp RUNTIME DESTINATION ".")
endif (WIN32)
