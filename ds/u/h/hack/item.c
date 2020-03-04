#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"萬能液晶平面螢幕"NOR,({"TFT LCD moniter","TFT","LCD","moniter"}));
        set("unit", "個");
        set("long",@LONG
一個透明的液晶螢幕，高度有一個人那麼高，遠看就像一個門，螢幕顯示著許多按鈕，目前正在測試階段。
如果你去觸碰(push)那些按鈕的話，說不定會有甚麼奇妙的事情發生。

LONG
);
        set_weight(999999);
        set("material","steel");
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        setup();
}

void init()

{
        add_action("do_push","push");
}

int do_push(string arg)
{
        object me;
        
        me=this_player();
        if(!arg) return notify_fail("你等了一會後，萬能液晶螢幕上什麼也沒有發生過．\n");
 if(arg=="dragon")
 {
         message_vision(WHT"突然萬能液晶平面螢幕的畫面上形成一條路，$N向螢幕裡走了進去，並且消失在這個房間裡了。\n"NOR, me);
         tell_room(environment(me),me->name()+"漸漸消失在螢幕中了。\n",({me}));
      write(HIR"你眼前的景象慢慢地顯現，而你發覺你眼前的就是狂龍幫的大廳了。\n"NOR); 
      me->move("/open/world1/cominging/area/dragon/dragon");
         return 1;
 }
 if(arg=="sky")
 {
         message_vision(WHT"突然萬能液晶平面螢幕的畫面上形成一條路，$N向螢幕裡走了進去，並且消失在這個房間裡了。\n"NOR, me);
         tell_room(environment(me),me->name()+"漸漸消失在螢幕中了。\n",({me}));
       write(HIG"  你眼前的景象慢慢地顯現，而你發覺你眼前的就是天地會的【長老房間】了。\n"NOR);
       me->move("/open/world1/acme/area/sky/room05");
         return 1;

 }
if(arg=="moon")
 {
         message_vision(WHT"突然萬能液晶平面螢幕的畫面上形成一條路，$N向螢幕裡走了進去，並且消失在這個房間裡了。\n"NOR, me);
         tell_room(environment(me),me->name()+"漸漸消失在螢幕中了。\n",({me}));
       write(HIC"  你眼前的景象慢慢地顯現，而你發覺你眼前的就是月族的月魂殿了。\n"NOR);
       me->move("/open/world1/acme/area/moon/room3");
         return 1;

 }
if(arg=="thief")
 {
         message_vision(WHT"突然萬能液晶平面螢幕的畫面上形成一條路，$N向螢幕裡走了進去，並且消失在這個房間裡了。\n"NOR, me);
         tell_room(environment(me),me->name()+"漸漸消失在螢幕中了。\n",({me}));
       write(MAG"  你眼前的景象慢慢地顯現，而你發覺你眼前的就是盜賊的盜賊工會了。\n"NOR);
       me->move("/open/world2/shengsan/aovandis/room100");
         return 1;

 }
if(arg=="god")
 {
         message_vision(WHT"突然萬能液晶平面螢幕的畫面上形成一條路，$N向螢幕裡走了進去，並且消失在這個房間裡了。\n"NOR, me);
         tell_room(environment(me),me->name()+"漸漸消失在螢幕中了。\n",({me}));
       write(HIM"  你眼前的景象慢慢地顯現，而你發覺你眼前的就是神武教的練武之地了。\n"NOR);
       me->move("/open/world1/acme/area/parlor");
         return 1;

 }
if(arg=="wind")
 {
         message_vision(WHT"突然萬能液晶平面螢幕的畫面上形成一條路，$N向螢幕裡走了進去，並且消失在這個房間裡了。\n"NOR, me);
         tell_room(environment(me),me->name()+"漸漸消失在螢幕中了。\n",({me}));
       write(HIG"  你眼前的景象慢慢地顯現，而你發覺你眼前的就是疾風門的疾風右使之房了。\n"NOR);
       me->move("/open/world1/cominging/area/flurry49");
         return 1;

 }
if(arg=="bagi")
 {
         message_vision(WHT"突然萬能液晶平面螢幕的畫面上形成一條路，$N向螢幕裡走了進去，並且消失在這個房間裡了。\n"NOR, me);
         tell_room(environment(me),me->name()+"漸漸消失在螢幕中了。\n",({me}));
       write(HIR"  你眼前的景象慢慢地顯現，而你發覺你眼前的就是八極門的石屋了。\n"NOR);
       me->move("/open/world1/tmr/area/s_house");
         return 1;

 }
if(arg=="bonze")
 {
         message_vision(WHT"突然萬能液晶平面螢幕的畫面上形成一條路，$N向螢幕裡走了進去，並且消失在這個房間裡了。\n"NOR, me);
         tell_room(environment(me),me->name()+"漸漸消失在螢幕中了。\n",({me}));
       write(HIB"  你眼前的景象慢慢地顯現，而你發覺你眼前的就是凌雲寺的大雄寶殿了。\n"NOR);
       me->move("/open/world1/acme/bonze/b16");
         return 1;

 }
if(arg=="mj")
 {
         message_vision(WHT"突然萬能液晶平面螢幕的畫面上形成一條路，$N向螢幕裡走了進去，並且消失在這個房間裡了。\n"NOR, me);
         tell_room(environment(me),me->name()+"漸漸消失在螢幕中了。\n",({me}));
       write(HIR"  你眼前的景象慢慢地顯現，而你發覺你眼前的就是夢幻七域遠近馳名的麻將屋了。\n"NOR);
       me->move("/open/world1/tmr/area/mjroom");
         return 1;

 }


         
}
