#include <ansi2.h>
inherit ROOM;

string file_path = "/open/world1/tmr/blood_field2/";         // �D����npc��m

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
int *mob_amount = ({ 100, 100, 100, 100, 100, 50, 30, 30});

/* mob���ͫ�n���쪺��m */
string *mob_born = ({
"map_7_1.c", "map_7_3.c", "map_7_5.c", "map_7_7.c", "map_7_9.c", 
"map_9_1.c", "map_9_3.c", "map_9_5.c", "map_9_7.c", "map_9_9.c", 
"map_11_11.c", "map_11_13.c", "map_11_15.c", "map_11_17.c", "map_11_19.c", 
"map_15_11.c", "map_15_13.c", "map_15_15.c", "map_15_17.c", "map_15_21.c", 
"map_18_11.c", "map_18_13.c", "map_18_15.c", "map_18_17.c", "map_18_20.c", 
"map_21_11.c", "map_21_13.c", "map_21_15.c", "map_21_17.c", "map_21_21.c", 
"map_22_11.c", "map_22_13.c", "map_22_15.c", "map_22_17.c", "map_22_23.c", 
"map_25_0.c", "map_25_3.c", "map_25_5.c", "map_25_7.c", "map_25_9.c", 
});

void create()
{
        set("short", "��a");
        set("long", @LONG

LONG
);
        set("exits",([
        "west" : __DIR__"map_25_23",
        "north" : __DIR__"map_24_24",
        "south" : "/open/world1/tmr/dragoncity/caodi11",
        ]));
    set("objects",([
        __DIR__"npc/warnpc" : 1, 
    ]));

        set("outdoors","forest");
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
        int amount, ct;
    string file;
    object mob;
    string room;

    file = file_path + "npc/" + mob_file[i];
    amount = sizeof(children(file));
    if( amount >= mob_amount[i] ) return;
    amount = mob_amount[i] - amount;
        ct = 0;
    // ���ͦܤ@�w�ƶq�� Mob
    while( amount && ct++ < 50 ) {
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
void start7() { do_start(7); }


void open_war()
{
        message("world:world1:vision",
HIR "\n\t        �N�I�N�I�N�I�uť�����S���J���Թ��n�j�@�I�I\n"
+HIW "\n\t�n�Ϧb��{���"HIR"�]�פj�x"HIW"�A�w�����i�J�ƾԪ��A�A�Ӫ̮���ŽסI�I\n\n" NOR
,users() );

        call_out( "start0", 1);
        call_out( "start0", 3);
//        call_out( "start0", 5);
        call_out( "start1", 7);
        call_out( "start1", 9);
  //      call_out( "start1", 11);
        call_out( "start2", 13);
        call_out( "start2", 15);
//        call_out( "start2", 17);
        call_out( "start3", 19);
        call_out( "start3", 21);
        call_out( "start4", 23);
        call_out( "start4", 25);
        call_out( "start5", 27);
        call_out( "start5", 29);
        call_out( "start6", 31);
        call_out( "start7", 33);
}

void start_war() {
    call_out("open_war", 7  );
}

