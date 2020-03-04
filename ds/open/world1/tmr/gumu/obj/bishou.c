// Room: /d/gumu/obj/bishou.c匕首
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name( "斬首匕" , ({ "behead dagger", "dagger" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這是一把邊緣鋒利的匕首，好像可以斬(chop)東西。\n");
                set("value", 0);
                set("material", "iron");
        }
        setup();
}

void init()
{
      add_action("mark_success", "chop");
}

int mark_success(string arg)
{
        object target, ob,name1, me = this_player();

        name1 = me->query("id"); 
    if(!arg) return notify_fail("你要斬什麼？\n");  
        target = present(arg, environment(me));  
        if(!target)
                return notify_fail("找不到這個東西。\n");
        if(!target->is_corpse())
                return notify_fail("看清楚點，那不是屍體。\n");
        if(target->query("no_head"))
                return notify_fail("那具屍體已經沒有首級了。\n");
        if(!target->is_character())
                return notify_fail("那具屍體已經腐爛了。\n");
        message_vision(HIR"$N揚起匕首 ，對準$n的脖子處猛地斬了下去！\n"NOR, me, target);
        ob=new(__DIR__"head");
        ob->set_name(target->query("victim_name")+"的首級",({"head"}));
        ob->set("long", "這是一顆"+target->query("victim_name")+"的首級。\n");    
        if(target->query("victim_user")) 
        ob->set("victim_user", 1);  
        if(target->query("kill_by")) 
        ob->set("kill_by", target->query("kill_by"));
        target->delete("kill_by");
        message_vision(HIR"$N將$n斬了下來，提在手中。\n"NOR, me, ob);
        ob->move(me);
        target->set("name", "無頭屍體");
        target->set("no_head", 1);
        target->set("long", "一具無頭屍體，腐臭四溢，情狀可怖。\n");           
        return 1;
}

