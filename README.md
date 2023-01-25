# samp-org-system

```pwn
native ORG:ORG_Create()
native bool:ORG_Destroy(ORG:id)
native bool:ORG_IsValid(ORG:id) 
native bool:ORG_SetName(ORG:id, const value[])
native ORG_GetName(ORG:id)
native bool:ORG_SetTag(ORG:id, const value[])
native ORG_GetTag(ORG:id)
native bool:ORG_SetColor(ORG:id, const value[])
native ORG_GetColor(ORG:id)
native bool:ORG_SetLeader(ORG:id, const value[])
native ORG_GetLeader(ORG:id)
native bool:ORG_SetMaxMembers(ORG:id, value)
native ORG_GetMaxMembers(ORG:id)
native bool:ORG_SetMaxRanks(ORG:id, value)
native ORG_GetMaxRanks(ORG:id)
native bool:ORG_SetMaxVehicles(ORG:id, value)
native ORG_GetMaxVehicles(ORG:id)

native ORGRank:ORG_AddRank(ORG:id, const value[])
native ORG_RemoveRank(ORG:id, ORGRank:index)
native bool:ORG_SetRank(ORG:id, ORGRank:index, const value[])
native ORG_GetRank(ORG:id, ORGRank:index)

native ORGMember:ORG_AddMember(ORG:id, const value[])
native ORG_RemoveMember(ORG:id, ORGMember:index)
native bool:ORG_SetMember(ORG:id, ORGMember:index, const value[])
native ORG_GetMember(ORG:id, ORGMember:index)

native bool:ORG_RemoveVehicle(ORG:id, ORGVehicle:index)
native bool:ORG_SetVehicle(ORG:id, ORGVehicle:index, vehicleid)
native ORG_GetVehicle(ORG:id, ORGVehicle:index)
```
