#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit WHIP;

void create() {  
        set_name("蛇牙", ({ "snake tooth", "tooth", "whip"}) ) ;
        set("long",@LONG
暗金剛器是一種變幻多端的武器，目前其中一種叫做「蛇牙」的鞭型態。
你可以使用<change +其他型態>，將暗金剛器換成其它種武器型態。
LONG
);
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_str",15);
        set("limit_con",15);
        set("limit_int",15);
        set("limit_dex",15);
        set("unit", "把");        
        set("value",1000);
        set("volume",3);        
        set("material","darksteel"); 
        set("replica_ob",__DIR__"steel_staff");      
               }       
        set("weapon_prop/con",-1);
        set("weapon_prop/dex",2);
        init_whip(40);
        setup();
 }

void init()
{
add_action("change_weapon","change");
}

int change_weapon(string arg)
{
 object me,staff,dagger,pike,sword,fist,obj;
 me=this_player();
 obj=this_object();
 if(this_player()->query("mp") < 300) 
 	return notify_fail("你的法力不足以啟動變型的力量。\n");

	switch(arg)
	{
            case "staff":
            {
            write(HIY"你開始將暗金剛器拆解，並重新組合...\n"+
                            "經過一番努力，你將之恢復成"HIC"暗金剛器原型...\n"NOR);
            me->receive_damage("mp",200);
	    staff = new_ob(__DIR__"ds_staff");
            staff->move(me);
            destruct(obj);
            return 1;
            }
            case "dagger":
            {
            write(HIY"你開始將暗金剛器拆解，並重新組合...\n"+
                            "經過一番努力，你組合出"HIC"暗金剛器之匕首型--龍咬...\n"NOR);
            me->receive_damage("mp",200);
            dagger=new_ob(__DIR__"ds_dagger"); 
            dagger->move(me);
            destruct(obj);
            return 1;
            }
            case "pike":
            {
            write(HIY"你開始將暗金剛器拆解，並重新組合...\n"+
                            "經過一番努力，你組合出"HIC"暗金剛器之槍型--鶴啄...\n"NOR);
            me->receive_damage("mp",200);
            pike=new_ob(__DIR__"ds_pike"); 
            pike->move(me);
            destruct(obj);
            return 1;
            }
            case "sword":
            {
            write(HIY"你開始將暗金剛器拆解，並重新組合...\n"+
                            "經過一番努力，你組合出"HIC"暗金剛器之劍型--虎吼...\n"NOR);
            me->receive_damage("mp",200);
            sword=new_ob(__DIR__"ds_sword"); 
            sword->move(me);
            destruct(obj);
            return 1;
            }
            case "fist":
            {
            write(HIY"你開始將暗金剛器拆解，並重新組合...\n"+
                            "經過一番努力，你組合出"HIC"暗金剛器之拳套型--豹\爪...\n"NOR);
            me->receive_damage("mp",200);
            fist=new_ob(__DIR__"ds_fist"); 
            fist->move(me);
            destruct(obj);
            return 1;
            }
       default: write("沒有這種型態。\n");
                return 1;
       }


  return 1;
}


