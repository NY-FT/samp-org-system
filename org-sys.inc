#if defined _INC_ORG_SYS_INCLUDED
	#endinput
#endif
#define _INC_ORG_SYS_INCLUDED

#include <open.mp>

#include <YSI_Data\y_iterate>
#include <YSI_Coding\y_malloc>

// defines

#define MAX_ORGS                    10

#define MAX_ORG_NAME                64
#define MAX_ORG_TAG                 4
#define ORG_COLOR_LENGHT            6
#define MAX_ORG_RANK_NAME           32

#define MAX_ORG_MEMBERS             25
#define MAX_ORG_RANKS               15
#define MAX_ORG_VEHICLES            15

#define INVALID_ORG_ID              ORG:-1
#define INVALID_ORG_RANK_ID         ORGRank:-1
#define INVALID_ORG_MEMBER_ID       ORGMember:-1
#define INVALID_ORG_VEHICLE_ID      ORGVehicle:-1

#define INVALID_ORG_NAME            "Sem Nome"
#define INVALID_ORG_TAG             "ORG"
#define INVALID_ORG_COLOR           "FFFFFF"
#define INVALID_ORG_LEADER          "Nenhum"
#define INVALID_ORG_RANK            "Sem Nome"
#define INVALID_ORG_MEMBER          "Nenhum"

// enumerators

enum E_ORG_DATA
{
    E_ORG_NAME[MAX_ORG_NAME + 1],
    E_ORG_TAG[MAX_ORG_TAG + 1],
    E_ORG_COLOR[ORG_COLOR_LENGHT + 1],
    E_ORG_LEADER[MAX_PLAYER_NAME + 1],

    E_ORG_MAXMEMBERS,
    E_ORG_MAXRANKS,
    E_ORG_MAXVEHICLES,

    E_ORG_VEHICLEID[ORGVehicle:MAX_ORG_VEHICLES]
};

static ORG_Data[ORG:MAX_ORGS][E_ORG_DATA];
static Alloc:ORG_RankName[ORG:MAX_ORGS][ORGRank:MAX_ORG_RANKS];
static Alloc:ORG_MemberName[ORG:MAX_ORGS][ORGMember:MAX_ORG_MEMBERS];

static Iterator:ORGs<MAX_ORGS>;
static Iterator:ORGRanks<MAX_ORGS, MAX_ORG_RANKS>;
static Iterator:ORGMembers<MAX_ORGS, MAX_ORG_MEMBERS>;
static Iterator:ORGVehicles<MAX_ORGS, MAX_ORG_VEHICLES>;

// functions

stock ORG:ORG_Create()
{
    new ORG:id = ORG:Iter_Alloc(ORGs);

    if(_:id == ITER_NONE) {
        return INVALID_ORG_ID;
    }

    format(ORG_Data[id][E_ORG_NAME], MAX_ORG_NAME+1, INVALID_ORG_NAME);
    format(ORG_Data[id][E_ORG_TAG], MAX_ORG_TAG+1, INVALID_ORG_TAG);
    format(ORG_Data[id][E_ORG_COLOR], ORG_COLOR_LENGHT+1, INVALID_ORG_COLOR);
    format(ORG_Data[id][E_ORG_LEADER], MAX_PLAYER_NAME+1, INVALID_ORG_LEADER);

    return id;
}

stock ORG_Destroy(ORG:id)
{
    if(!(0 <= _:id < MAX_ORGS)) {
        return 0;
    }

    if(!Iter_Contains(ORGs, _:id)) {
        return 0;
    }

    ORG_Data[id][E_ORG_NAME][0]     = '\0';
    ORG_Data[id][E_ORG_TAG][0]      = '\0';
    ORG_Data[id][E_ORG_COLOR][0]    = '\0';
    ORG_Data[id][E_ORG_LEADER][0]   = '\0';

    ORG_Data[id][E_ORG_MAXMEMBERS]  = 0;
    ORG_Data[id][E_ORG_MAXRANKS]    = 0;
    ORG_Data[id][E_ORG_MAXVEHICLES] = 0;

    new ORGRank:a;
    new ORGMember:b;
    new ORGVehicle:c;

    foreach((_:a): ORGRanks<_:id>) {
        free(ORG_RankName[id][a]);
    }

    foreach((_:b): ORGMembers<_:id>) {
        free(ORG_MemberName[id][b]);
    }

    foreach((_:c): ORGVehicles<_:id>) {
        ORG_Data[id][E_ORG_VEHICLEID][c] = INVALID_VEHICLE_ID;
    }

    Iter_Clear(ORGRanks<_:id>);
    Iter_Clear(ORGMembers<_:id>);
    Iter_Clear(ORGVehicles<_:id>);

    Iter_Remove(ORGs, _:id);

    return 1;
}

stock bool:ORG_IsValid(ORG:id) 
{
    if(!(0 <= _:id < MAX_ORGS)) {
        return false;
    }

    if(!Iter_Contains(ORGs, _:id)) {
        return false;
    }

    return true;
}

stock bool:ORG_SetName(ORG:id, const value[])
{
    if(!(0 <= _:id < MAX_ORGS)) {
        return false;
    }

    if(!Iter_Contains(ORGs, _:id)) {
        return false;
    }

    format(ORG_Data[id][E_ORG_NAME], MAX_ORG_NAME+1, value);
    return true;
}

stock ORG_GetName(ORG:id)
{
    new ret[MAX_ORG_NAME + 1] = INVALID_ORG_NAME;

    if(!(0 <= _:id < MAX_ORGS)) {
        return ret;
    }

    if(!Iter_Contains(ORGs, _:id)) {
        return ret;
    }

    format(ret, sizeof(ret), ORG_Data[id][E_ORG_NAME]);
    return ret;
}

stock bool:ORG_SetTag(ORG:id, const value[])
{
    if(!(0 <= _:id < MAX_ORGS)) {
        return false;
    }

    if(!Iter_Contains(ORGs, _:id)) {
        return false;
    }

    format(ORG_Data[id][E_ORG_TAG], MAX_ORG_TAG+1, value);
    return true;
}

stock ORG_GetTag(ORG:id)
{
    new ret[MAX_ORG_TAG + 1] = INVALID_ORG_TAG;

    if(!(0 <= _:id < MAX_ORGS)) {
        return ret;
    }

    if(!Iter_Contains(ORGs, _:id)) {
        return ret;
    }

    format(ret, sizeof(ret), ORG_Data[id][E_ORG_TAG]);
    return ret;
}

stock bool:ORG_SetColor(ORG:id, const value[])
{
    if(!(0 <= _:id < MAX_ORGS)) {
        return false;
    }

    if(!Iter_Contains(ORGs, _:id)) {
        return false;
    }

    format(ORG_Data[id][E_ORG_COLOR], ORG_COLOR_LENGHT+1, value);
    return true;
}

stock ORG_GetColor(ORG:id)
{
    new ret[ORG_COLOR_LENGHT + 1] = INVALID_ORG_COLOR;

    if(!(0 <= _:id < MAX_ORGS)) {
        return ret;
    }

    if(!Iter_Contains(ORGs, _:id)) {
        return ret;
    }

    format(ret, sizeof(ret), ORG_Data[id][E_ORG_COLOR]);
    return ret;
}

stock bool:ORG_SetLeader(ORG:id, const value[])
{
    if(!(0 <= _:id < MAX_ORGS)) {
        return false;
    }

    if(!Iter_Contains(ORGs, _:id)) {
        return false;
    }

    format(ORG_Data[id][E_ORG_LEADER], MAX_PLAYER_NAME+1, value);
    return true;
}

stock ORG_GetLeader(ORG:id)
{
    new ret[MAX_PLAYER_NAME + 1] = INVALID_ORG_LEADER;

    if(!(0 <= _:id < MAX_ORGS)) {
        return ret;
    }

    if(!Iter_Contains(ORGs, _:id)) {
        return ret;
    }

    format(ret, sizeof(ret), ORG_Data[id][E_ORG_LEADER]);
    return ret;
}

stock bool:ORG_SetMaxMembers(ORG:id, value)
{
    if(!(0 <= _:id < MAX_ORGS)) {
        return false;
    }

    if(!Iter_Contains(ORGs, _:id)) {
        return false;
    }

    ORG_Data[id][E_ORG_MAXMEMBERS] = value;
    return true;
}

stock ORG_GetMaxMembers(ORG:id)
{
    if(!(0 <= _:id < MAX_ORGS)) {
        return 0;
    }

    if(!Iter_Contains(ORGs, _:id)) {
        return 0;
    }

    return ORG_Data[id][E_ORG_MAXMEMBERS];
}

stock bool:ORG_SetMaxRanks(ORG:id, value)
{
    if(!(0 <= _:id < MAX_ORGS)) {
        return false;
    }

    if(!Iter_Contains(ORGs, _:id)) {
        return false;
    }

    ORG_Data[id][E_ORG_MAXRANKS] = value;
    return true;
}

stock ORG_GetMaxRanks(ORG:id)
{
    if(!(0 <= _:id < MAX_ORGS)) {
        return 0;
    }

    if(!Iter_Contains(ORGs, _:id)) {
        return 0;
    }

    return ORG_Data[id][E_ORG_MAXRANKS];
}

stock bool:ORG_SetMaxVehicles(ORG:id, value)
{
    if(!(0 <= _:id < MAX_ORGS)) {
        return false;
    }

    if(!Iter_Contains(ORGs, _:id)) {
        return false;
    }

    ORG_Data[id][E_ORG_MAXVEHICLES] = value;
    return true;
}

stock ORG_GetMaxVehicles(ORG:id)
{
    if(!(0 <= _:id < MAX_ORGS)) {
        return 0;
    }

    if(!Iter_Contains(ORGs, _:id)) {
        return 0;
    }

    return ORG_Data[id][E_ORG_MAXVEHICLES];
}

// rank

stock ORGRank:ORG_AddRank(ORG:id, const value[])
{
    new ORGRank:index = ORGRank:Iter_Alloc(ORGRanks<_:id>);

    if(_:index == ITER_NONE) {
        return INVALID_ORG_RANK_ID;
    }

    ORG_RankName[id][index] = Malloc_NewS(value);

    return index;
}

stock ORG_RemoveRank(ORG:id, ORGRank:index)
{
    if(!(0 <= _:id < MAX_ORGS)) {
        return false;
    }

    if(!Iter_Contains(ORGs, _:id)) {
        return false;
    }

    if(!(0 <= _:index < MAX_ORG_RANKS)) {
        return false;
    }

    if(!Iter_Contains(ORGRanks<_:id>, _:index)) {
        return false;
    }

    ORG_RankName[id][index] = Malloc_NewS(INVALID_ORG_RANK);

    Iter_Remove(ORGRanks<_:id>, _:index);

    return true;
}

stock bool:ORG_SetRank(ORG:id, ORGRank:index, const value[])
{
    if(!(0 <= _:id < MAX_ORGS)) {
        return false;
    }

    if(!Iter_Contains(ORGs, _:id)) {
        return false;
    }

    if(!(0 <= _:index < MAX_ORG_RANKS)) {
        return false;
    }

    if(!Iter_Contains(ORGRanks<_:id>, _:index)) {
        return false;
    }

    ORG_RankName[id][index] = Malloc_NewS(value);
    return true;
}

stock ORG_GetRank(ORG:id, ORGRank:index)
{
    new ret[MAX_ORG_RANK_NAME + 1] = INVALID_ORG_RANK;

    if(!(0 <= _:id < MAX_ORGS)) {
        return ret;
    }

    if(!Iter_Contains(ORGs, _:id)) {
        return ret;
    }

    if(!(0 <= _:index < MAX_ORG_RANKS)) {
        return ret;
    }

    if(!Iter_Contains(ORGRanks<_:id>, _:index)) {
        return ret;
    }

    Malloc_GetS(ret, sizeof(ret), ORG_RankName[id][index], 0);
    return ret;
}

// member

stock ORGMember:ORG_AddMember(ORG:id, const value[])
{
    new ORGMember:index = ORGMember:Iter_Alloc(ORGMembers<_:id>);

    if(_:index == ITER_NONE) {
        return INVALID_ORG_MEMBER_ID;
    }

    ORG_MemberName[id][index] = Malloc_NewS(value);

    return index;
}

stock ORG_RemoveMember(ORG:id, ORGMember:index)
{
    if(!(0 <= _:id < MAX_ORGS)) {
        return false;
    }

    if(!Iter_Contains(ORGs, _:id)) {
        return false;
    }

    if(!(0 <= _:index < MAX_ORG_MEMBERS)) {
        return false;
    }

    if(!Iter_Contains(ORGMembers<_:id>, _:index)) {
        return false;
    }

    ORG_MemberName[id][index] = Malloc_NewS(INVALID_ORG_MEMBER);

    Iter_Remove(ORGMembers<_:id>, _:index);

    return true;
}

stock bool:ORG_SetMember(ORG:id, ORGMember:index, const value[])
{
    if(!(0 <= _:id < MAX_ORGS)) {
        return false;
    }

    if(!Iter_Contains(ORGs, _:id)) {
        return false;
    }

    if(!(0 <= _:index < MAX_ORG_MEMBERS)) {
        return false;
    }

    if(!Iter_Contains(ORGMembers<_:id>, _:index)) {
        return false;
    }

    ORG_MemberName[id][index] = Malloc_NewS(value);
    return true;
}

stock ORG_GetMember(ORG:id, ORGMember:index)
{
    new ret[MAX_PLAYER_NAME + 1] = INVALID_ORG_MEMBER;

    if(!(0 <= _:id < MAX_ORGS)) {
        return ret;
    }

    if(!Iter_Contains(ORGs, _:id)) {
        return ret;
    }

    if(!(0 <= _:index < MAX_ORG_MEMBERS)) {
        return ret;
    }

    if(!Iter_Contains(ORGMembers<_:id>, _:index)) {
        return ret;
    }

    Malloc_GetS(ret, sizeof(ret), ORG_MemberName[id][index], 0);
    return ret;
}

// vehicles

stock ORGVehicle:ORG_AddVehicle(ORG:id, vehicleid)
{
    if(!IsValidVehicle(vehicleid)) {
        return INVALID_ORG_VEHICLE_ID;
    }

    new ORGVehicle:index = ORGVehicle:Iter_Alloc(ORGVehicles<_:id>);

    if(_:index == ITER_NONE) {
        return INVALID_ORG_VEHICLE_ID;
    }

    ORG_Data[id][E_ORG_VEHICLEID][index] = vehicleid;

    return index;
}

stock bool:ORG_RemoveVehicle(ORG:id, ORGVehicle:index)
{
    if(!(0 <= _:id < MAX_ORGS)) {
        return false;
    }

    if(!Iter_Contains(ORGs, _:id)) {
        return false;
    }

    if(!(0 <= _:index < MAX_ORG_VEHICLES)) {
        return false;
    }

    if(!Iter_Contains(ORGVehicles<_:id>, _:index)) {
        return false;
    }

    DestroyVehicle(ORG_Data[id][E_ORG_VEHICLEID][index]);

    Iter_Remove(ORGVehicles<_:id>, _:index);

    return true;
}

stock bool:ORG_SetVehicle(ORG:id, ORGVehicle:index, vehicleid)
{
    if(!(0 <= _:id < MAX_ORGS)) {
        return false;
    }

    if(!Iter_Contains(ORGs, _:id)) {
        return false;
    }

    if(!(0 <= _:index < MAX_ORG_VEHICLES)) {
        return false;
    }

    if(!Iter_Contains(ORGVehicles<_:id>, _:index)) {
        return false;
    }

    ORG_Data[id][E_ORG_VEHICLEID][index] = vehicleid;
    return true;
}

stock ORG_GetVehicle(ORG:id, ORGVehicle:index)
{
    if(!(0 <= _:id < MAX_ORGS)) {
        return INVALID_VEHICLE_ID;
    }

    if(!Iter_Contains(ORGs, _:id)) {
        return INVALID_VEHICLE_ID;
    }

    if(!(0 <= _:index < MAX_ORG_VEHICLES)) {
        return INVALID_VEHICLE_ID;
    }

    if(!Iter_Contains(ORGVehicles<_:id>, _:index)) {
        return INVALID_VEHICLE_ID;
    }

    return ORG_Data[id][E_ORG_VEHICLEID][index];
}
