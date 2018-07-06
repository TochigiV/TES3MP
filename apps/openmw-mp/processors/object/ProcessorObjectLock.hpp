#ifndef OPENMW_PROCESSOROBJECTLOCK_HPP
#define OPENMW_PROCESSOROBJECTLOCK_HPP

#include "../ObjectProcessor.hpp"

namespace mwmp
{
    class ProcessorObjectLock : public ObjectProcessor
    {
    public:
        ProcessorObjectLock()
        {
            BPP_INIT(ID_OBJECT_LOCK)
        }

        void Do(ObjectPacket &packet, Player &player, BaseObjectList &objectList) override
        {
            LOG_MESSAGE_SIMPLE(Log::LOG_INFO, "Received %s from %s", strPacketID.c_str(), player.npc.mName.c_str());
            
            Script::Call<Script::CallbackIdentity("OnObjectLock")>(player.getId(), objectList.cell.getDescription().c_str());
        }
    };
}

#endif //OPENMW_PROCESSOROBJECTLOCK_HPP
