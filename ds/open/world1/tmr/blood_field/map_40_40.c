#include <ansi2.h>
inherit ROOM;

string file_path = "/open/world1/tmr/blood_field/";         // �D����npc��m

/* mob���ɮצ�m */
string *mob_file = ({ 
                      "fetish.c",
                      "cat.c",
                      "fetish_wizard.c",
                      "hulks.c",
                      "wendigo.c",
                      "wild_toast.c",
                      "ents.c",
                      "ents2.c",
                   });
                      
/* mob�ҭn���ͪ��ƶq */
int *mob_amount = ({ 50, 50, 50, 50, 50, 50, 30, 30});

/* mob���ͫ�n���쪺��m */
string *mob_born = ({
"map_23_10.c", "map_23_11.c", "map_23_12.c", "map_23_13.c", "map_23_14.c", 
"map_19_11.c", "map_23_12.c", "map_23_14.c", "map_23_16.c", "map_23_17.c", 
"map_15_10.c", "map_23_11.c", "map_23_12.c", "map_23_13.c", "map_23_14.c", 
"map_9_0.c", "map_9_1.c","map_9_2.c", "map_9_3.c","map_9_4.c", "map_9_5.c",
"map_9_40.c", "map_9_39.c","map_9_38.c", "map_9_37.c","map_9_36.c", "map_9_35.c",  
"map_38_10.c", "map_38_12.c", "map_38_14.c", "map_38_18.c", "map_38_21.c", 
"map_38_27.c", "map_38_29.c", "map_38_30.c", "map_38_31.c", "map_38_32.c", 
});
                      
void create()
{
        set("short", "���");
        set("long", @LONG

LONG
);
        set("exits",([
        "west" : __DIR__"map_40_39",
        "south" : "/open/world1/tmr/dragoncity/caodi11",
        ]));
        set("objects",([
        __DIR__"npc/warnpc" : 1, 
                
                ]));
        set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
}



void init()
{
    object me=this_player();
    if(me->id("_BLOOD_FIELD_NPC_") ) {
        me->force_me("say �ڹ��{��~���@�ɨS�����򿳽�C");
        me->force_me("go west");
    }
}



void do_start(int i)
{
        int amount;
    string file;
    object mob;
    string room;

    file = file_path + "npc/" + mob_file[i];
    amount = sizeof(children(file));
    if( amount >= mob_amount[i] ) return;
    amount = mob_amount[i] - amount;
    // ���ͦܤ@�w�ƶq�� Mob
    while( amount ) {
        mob = new(file);
        if(!mob) return;
        room = file_path + mob_born[random(sizeof(mob_born))];
        if(!room) continue;
        amount--;
        mob->move(room);
   }
}

void start0() { do_start(0); }
void start1() { do_start(1); }
void start2() { do_start(2); }
void start3() { do_start(3); }
void start4() { do_start(4); }
void start5() { do_start(5); }
void start6() { do_start(6); }


void open_war()
{
        message("world:world1:vision",
HIR "\n\t        �N�I�N�I�N�I�uť�����S���J���Թ��n�j�@�I�I\n"
+HIM "\n\t�n�Ϧb��{���"HIR"�]��"HIM"�j�x�A�w�����i�J�ƾԪ��A�A�Ӫ̮���ŽסI�I\n\n" NOR
,users() );

        call_out( "start0", 1);
        call_out( "start0", 3);
        call_out( "start0", 5);
        call_out( "start1", 7);
        call_out( "start1", 9);
        call_out( "start1", 11);
        call_out( "start2", 13);
        call_out( "start2", 15);
        call_out( "start2", 17);
        call_out( "start3", 19);
        call_out( "start3", 21);
        call_out( "start4", 23);
        call_out( "start4", 25);
        call_out( "start5", 27);
        call_out( "start5", 29);
        call_out( "start6", 31);
        call_out( "start7", 33);

        call_out( "start0", 35);
        call_out( "start1", 37);
        call_out( "start2", 39);
        call_out( "start3", 41);
        call_out( "start4", 43);
        call_out( "start5", 45);
}

void start_war() {
//     call_out("open_war", 7  );
}


