#include <ansi.h>
#include <path.h>

inherit ITEM;

string *animal_files = ({
  "tiger_war.c",
  "rod_war.c",
  "snake_war.c",
  "leopard_war.c",
  "wildcat_war.c",
  "boar_war.c",
  "bear_war.c",
});

string *locate = ({
  "2f2.c",
  "3f1.c",
  "3f3.c",
  "4f1.c",
  "4f2.c",
  "1f2.c",
  "1f4.c",
});

string *room = ({
  "/open/world1/cominging/purple_sun/1f5.c",    // 下山的路
//  "/open/world1/cominging/purple_sun/psin7.c",
});

void create()
{
        set_name(HBK "大石盤" NOR, ({ "stone dish", "dish" }));
        set("long", "一個很大的石盤, 你可以試看看用 lay 放東西在上面 lay xxx on stone dish。 \n");
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "個");
                set("value", 0);
                set("no_sac", 1);
                set("no_get", 1);
                set("no_sell",1);
        }
        setup();
}

void open_war(object me);
void end_war();
int query_ghost();

void init()
{
        add_action("do_lay", "lay");
}

int do_lay(string arg)
{
        object me = this_player(), d_stone;
        string ob, on;

        if( !arg || sscanf(arg, "%s on %s", ob, on) != 2 )
                return notify_fail("你想要放什麼東西上去？\n");
        if( !objectp( d_stone = present( ob , me ) ) )
                return notify_fail("你身上沒有這個東西！\n");
        if( on != "stone dish" )
                return notify_fail("你要將"+d_stone->name()+"放在那？\n");
if( !d_stone->id("open-war-stone") && !d_stone->id("open-war-head") )
                return notify_fail("你把"+d_stone->name()+"放在大石盤上，但是什麼事也沒有發生。\n");
if( query_ghost() || query("war_start") )
                return notify_fail("你把"+d_stone->name()+"放在大石盤上，但是什麼事也沒有發生。\n");

set("war_start", 1);
message_vision(HIC"$N把$n放到大石盤。\n"NOR, me, d_stone);
me->start_busy(2);
destruct(d_stone);              // 元氣石
call_out("open_war",3, me);
return 1;
}

void open_war(object me)
{
        int i, j;
        object g, animals;

        message("world:world1:vision",
HIM"\n\t"+me->query("name") +HIM "解開紫陽山上邪惡領主獸王的封印，引來冷酷無情的狂獸大軍......\n\n"
HIR "\t\t紫陽山頂上狂獸暴動，殺生無數，生物盡皆惶恐逃生！！\n\n" NOR
,users() );

        // 獸王
         g = new( COMINGING_PAST + "purple_sun/npc/king" );
         g->move( COMINGING_PAST+"purple_sun/hole5" );
    
        // 一般動物
        for(i=0;i<sizeof(animal_files);i++)
        {
for(j = 0 ; j < 2 + random(4); j++)
{
animals = new(COMINGING_PAST+"purple_sun/npc/" + animal_files[i]);
animals->move(COMINGING_PAST+"purple_sun/" + locate[random(sizeof(locate))]);
}
}
/*
for(i=0;i<sizeof(room);i++)
load_object(room[i])->fall_stone();     // 引發落石，無法下山
*/

        call_out("end_war",180);
        return;
}

void end_war()
{
        object ghost;

        if( query_ghost() ) {
        call_out("end_war",30);
return;
}

set("war_start", 0);
        message("world:world1:vision",
CYN"\n\t紫陽山頂上狂獸盡除，又回復平時的寧靜了......\n\n" NOR
        ,users() );
}

int query_ghost()
{
        object ani;

        while( objectp(ani=find_living("animal-war-object")) )
        {
                if( !environment(ani) )
                {
                        destruct(ani);
                        ani = 0;
                }
                else break;
        }

        if( objectp(ani) ) return 1;
        
        return 0;
}

