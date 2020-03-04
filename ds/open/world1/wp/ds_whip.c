#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit WHIP;

void create() {  
        set_name("�D��", ({ "snake tooth", "tooth", "whip"}) ) ;
        set("long",@LONG
�t���边�O�@���ܤۦh�ݪ��Z���A�ثe�䤤�@�إs���u�D���v���@���A�C
�A�i�H�ϥ�<change +��L���A>�A�N�t���边�����䥦�تZ�����A�C
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
        set("unit", "��");        
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
 	return notify_fail("�A���k�O�����H�Ұ��ܫ����O�q�C\n");

	switch(arg)
	{
            case "staff":
            {
            write(HIY"�A�}�l�N�t���边��ѡA�í��s�զX...\n"+
                            "�g�L�@�f�V�O�A�A�N����_��"HIC"�t���边�쫬...\n"NOR);
            me->receive_damage("mp",200);
	    staff = new_ob(__DIR__"ds_staff");
            staff->move(me);
            destruct(obj);
            return 1;
            }
            case "dagger":
            {
            write(HIY"�A�}�l�N�t���边��ѡA�í��s�զX...\n"+
                            "�g�L�@�f�V�O�A�A�զX�X"HIC"�t���边���P����--�s�r...\n"NOR);
            me->receive_damage("mp",200);
            dagger=new_ob(__DIR__"ds_dagger"); 
            dagger->move(me);
            destruct(obj);
            return 1;
            }
            case "pike":
            {
            write(HIY"�A�}�l�N�t���边��ѡA�í��s�զX...\n"+
                            "�g�L�@�f�V�O�A�A�զX�X"HIC"�t���边���j��--�b��...\n"NOR);
            me->receive_damage("mp",200);
            pike=new_ob(__DIR__"ds_pike"); 
            pike->move(me);
            destruct(obj);
            return 1;
            }
            case "sword":
            {
            write(HIY"�A�}�l�N�t���边��ѡA�í��s�զX...\n"+
                            "�g�L�@�f�V�O�A�A�զX�X"HIC"�t���边���C��--��q...\n"NOR);
            me->receive_damage("mp",200);
            sword=new_ob(__DIR__"ds_sword"); 
            sword->move(me);
            destruct(obj);
            return 1;
            }
            case "fist":
            {
            write(HIY"�A�}�l�N�t���边��ѡA�í��s�զX...\n"+
                            "�g�L�@�f�V�O�A�A�զX�X"HIC"�t���边�����M��--�\\��...\n"NOR);
            me->receive_damage("mp",200);
            fist=new_ob(__DIR__"ds_fist"); 
            fist->move(me);
            destruct(obj);
            return 1;
            }
       default: write("�S���o�ث��A�C\n");
                return 1;
       }


  return 1;
}


