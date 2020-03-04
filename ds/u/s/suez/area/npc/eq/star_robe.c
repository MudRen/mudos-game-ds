#include <armor.h>

inherit SURCOAT;

inherit F_UNIQUE;


void create()

{
set_name("破布",({"cloth"}) );


      set_weight(210);

        if( clonep() )
   
set_default_object(__FILE__);

        else {

set("long","一塊不起眼的破布。");

                set("material", "cloth");

                set("unit", "片");

                set("value", 7);

        }

        setup();
}
void init()
{
       add_action("do_search","search");   
}
int do_search(string arg)
{
        object me,obj;
        me=this_player();
        obj=this_object(); 

        if (arg != "破布" && arg !="cloth" )
                return 0;
        else
        {
        tell_object(me,"你仔細的看了看這塊破布，發現原來這是至寶晨星披風！！！\n");
        obj->set_name("晨星披風",({"star robe","robe"}) );

        obj->set("long",           
                 "一塊不起眼的破布，只有擁有者才知道那不是普通的東西。\n"

                 "不但輕巧又刀槍不入，而且充滿了神秘的力量，可惜其貌不\n"

                 "揚，丟在路上誰也不知道是件寶物。也正因為如此，所以才\n"

                 "沒有人爭奪它，所以你才能夠得到它。\n");


      obj->set("armor_prop/armor", 7);

        obj->set("armor_prop/shield", 17);

        obj->set("armor_prop/dex", 2);

        obj->set("armor_prop/int", 2);

        obj->set("armor_prop/str", 1);

        obj->set("armor_prop/con", 1);

        obj->set("armor_prop/dodge", 7);
        return 1;
        }

}
