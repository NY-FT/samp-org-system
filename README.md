# samp-org-system

Stocks

```pwn
stock ORG:ORG_Create();
stock bool:ORG_Destroy(ORG:id);
stock bool:ORG_IsValid(ORG:id);
stock bool:ORG_SetName(ORG:id, const value[]);
stock ORG_GetName(ORG:id);
stock bool:ORG_SetTag(ORG:id, const value[]);
stock ORG_GetTag(ORG:id);
stock bool:ORG_SetColor(ORG:id, const value[]);
stock ORG_GetColor(ORG:id);
stock bool:ORG_SetLeader(ORG:id, const value[]);
stock ORG_GetLeader(ORG:id);
stock bool:ORG_SetMaxMembers(ORG:id, value);
stock ORG_GetMaxMembers(ORG:id);
stock bool:ORG_SetMaxRanks(ORG:id, value);
stock ORG_GetMaxRanks(ORG:id);
stock bool:ORG_SetMaxVehicles(ORG:id, value);
stock ORG_GetMaxVehicles(ORG:id);

stock ORGRank:ORG_AddRank(ORG:id, const value[]);
stock bool:ORG_RemoveRank(ORG:id, ORGRank:index);
stock bool:ORG_SetRank(ORG:id, ORGRank:index, const value[]);
stock ORG_GetRank(ORG:id, ORGRank:index);

stock ORGMember:ORG_AddMember(ORG:id, const value[]);
stock bool:ORG_RemoveMember(ORG:id, ORGMember:index);
stock bool:ORG_SetMember(ORG:id, ORGMember:index, const value[]);
stock ORG_GetMember(ORG:id, ORGMember:index);

stock ORGVehicle:ORG_AddVehicle(ORG:id, vehicleid);
stock bool:ORG_RemoveVehicle(ORG:id, ORGVehicle:index);
stock bool:ORG_SetVehicle(ORG:id, ORGVehicle:index, vehicleid);
stock ORG_GetVehicle(ORG:id, ORGVehicle:index);
```
