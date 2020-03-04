// File: /d/crush_bone/map_23_4.c
// Updated by tmr (Sat Jun 19 19:41:34 2004)

#include <ansi.h>

inherit ROOM;

string file_path = "/open/world1/tmr/crush_bone/";         // �D����npc��m

/* mob���ɮצ�m */
string *mob_file = ({ "orc_follower.c",
                      "orc.c",
                      "orc_hundred_leader.c",
                      "orc_thousand_leader.c",
                      "orc_commander.c",
                      "orc_herald.c",
                      "orc_envoy.c",
                      "orc_emperor.c"
                   });

/* mob�ҭn���ͪ��ƶq */
int *mob_amount = ({ 40, 40, 40, 40, 40, 40, 40, 1 });

/* mob���ͫ�n���쪺��m */
string *mob_born1 = ({ "map_22_1.c",
                       "map_11_1.c",
                       "map_1_1.c",
                       "map_1_12.c",
                       "map_1_22.c",
                       "map_11_22.c",
                       "map_22_22.c",
                       "map_22_12.c"
                   });

string *mob_born2 = ({ "map_7_9.c",
                       "map_9_16.c",
                       "map_11_9.c",
                       "map_13_16.c",
                       "map_16_14.c",
                       "map_16_10.c",
                       "map_13_7.c",
                       "map_7_7.c"
                   });


void create()
{
          set("short", "�p�|");
          set("long", @LONG

LONG
          );
          set("outdoors", "land");
          set("map_long", 1);
          set("exits", ([ /* 3 element(s) */
        "north" : __DIR__"map_22_4",
      "southwest" : "/open/world1/tmr/dragoncity/caodi8",
]));

        setup();
}
void init()
{
    object me=this_player();
    if(me->id("_CRUSH_BONE_ORC_") ) {
        me->force_me("say �ثe�٤���~�X�A�n���H����p���@�n�ǳơA�ӫҸU���U���U�U���I�I");
        me->force_me("go north");
    }
}

void do_start()
{
      int i, amount;
    string file;
    object mob;
    string room;

    for(i=0;i<3;i++) {

        file = file_path + "npc/" + mob_file[i];
        amount = sizeof(children(file));

        if( amount < mob_amount[i] ) {
            amount = mob_amount[i] - amount;

            // ���ͦܤ@�w�ƶq�� Mob
            while( amount-- ) {
                mob = new(file);
                room = file_path + mob_born1[random(sizeof(mob_born1))];
                mob->move(room);
            }
        }        
    }
}

void do_start2()
{
      int i, amount;
    string file;
    object mob;
    string room;

    for(i=3;i<6;i++) {

        file = file_path + "npc/" + mob_file[i];
        amount = sizeof(children(file));

        if( amount < mob_amount[i] ) {
            amount = mob_amount[i] - amount;

            // ���ͦܤ@�w�ƶq�� Mob
            while( amount-- ) {
                mob = new(file);
                // �x�Ϊ����ťH�W��MOB
                room = file_path + mob_born2[random(sizeof(mob_born2))];
                mob->move(room);
            }
        }        
    }
}


void do_start3()
{
      int i, amount;
    string file;
    object mob;
    string room;

    for(i=6;i<8;i++) {

        file = file_path + "npc/" + mob_file[i];
        amount = sizeof(children(file));

        if( amount < mob_amount[i] ) {
            amount = mob_amount[i] - amount;

            // ���ͦܤ@�w�ƶq�� Mob
            while( amount-- ) {
                mob = new(file);
                // �x�Ϊ����ťH�W��MOB
                room = file_path + mob_born2[random(sizeof(mob_born2))];
                mob->move(room);
            }
        }        
    }
}



void open_war()
{
        message("world:world1:vision",
HIR "\n\t        �N�I�N�I�N�I�uť�����S���J���Թ��n�j�@�I�I\n"
+HIG "\n\t�H����b�~�H�j�x�i�n�뤺�A�w�����i�J�ƾԪ��A�I�I\n\n" NOR
,users() );

        call_out( "do_start", 2);
        call_out( "do_start2", 8);
        call_out( "do_start3", 16);
}

void start_war() {
  call_out("open_war", 12  );
}


