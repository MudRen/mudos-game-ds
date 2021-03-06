#include <ansi2.h>
inherit ROOM;

string file_path = "/open/world1/tmr/blood_field/";         // 求援的npc位置

/* mob的檔案位置 */
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
                      
/* mob所要產生的數量 */
int *mob_amount = ({ 50, 50, 50, 50, 50, 50, 30, 30});

/* mob產生後要移到的位置 */
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
        set("short", "血跡");
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
        me->force_me("say 我對血腥荒野外的世界沒有什麼興趣。");
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
    // 產生至一定數量的 Mob
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
HIR "\n\t        咚！咚！咚！只聽見奧特蘭克的戰鼓聲大作！！\n"
+HIM "\n\t駐紮在血腥荒野的"HIR"夜禍"HIM"大軍，已全面進入備戰狀態，來者格殺勿論！！\n\n" NOR
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


