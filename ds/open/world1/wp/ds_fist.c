#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit FIST;

void create() {
        set_name("�\\��", ({ "leopard claw", "claw", "fist"}) ) ;
        set("long",@LONG
�t���边�����M���A�A�W���u�\���v�C
�A�i�H�A�յ�<change>��L���A�A�άOchange staff�^��t���边��ΡC
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
        set("volume",2);        
        set("material","darksteel"); 
        set("replica_ob",__DIR__"../wp/steel_staff");      
               }       
        set("weapon_prop/int",-1);
        set("weapon_prop/str",2);
        init_fist(55);
        setup();
 }

void init()
{
add_action("change_weapon","change");
}

int change_weapon(string arg)
{
 object me,staff,dagger,pike,whip,sword,obj;
 me=this_player();
 obj=this_object();
 if(this_player()->query("mp") > 300) 
  {switch(arg){
            case "staff":
            {
            write(HIY"�A�}�l�N�t���边��ѡA�í��s�զX...\n"+
                            "�g�L�@�f�V�O�A�A�N����_��"HIC"�t���边�쫬...\n"NOR);
            me->receive_damage("mp",200);
            staff=new_ob(__DIR__"../wp/ds_staff"); 
            staff->move(me);
            destruct(obj);
            return 1;
            }
            case "dagger":
            {
            write(HIY"�A�}�l�N�t���边��ѡA�í��s�զX...\n"+
                            "�g�L�@�f�V�O�A�A�զX�X"HIC"�t���边���P����--�s�r...\n"NOR);
            me->receive_damage("mp",200);
            dagger=new_ob(__DIR__"../wp/ds_dagger"); 
            dagger->move(me);
            destruct(obj);
            return 1;
            }
            case "pike":
            {
            write(HIY"�A�}�l�N�t���边��ѡA�í��s�զX...\n"+
                            "�g�L�@�f�V�O�A�A�զX�X"HIC"�t���边���j��--�b��...\n"NOR);
            me->receive_damage("mp",200);
            pike=new_ob(__DIR__"../wp/ds_pike"); 
            pike->move(me);
            destruct(obj);
            return 1;
            }
            case "whip":
            {
            write(HIY"�A�}�l�N�t���边��ѡA�í��s�զX...\n"+
                            "�g�L�@�f�V�O�A�A�զX�X"HIC"�t���边���@��--�D��...\n"NOR);
            me->receive_damage("mp",200);
            whip=new_ob(__DIR__"../wp/ds_whip"); 
            whip->move(me);
            destruct(obj);
            return 1;
            }
            case "sword":
            {
            write(HIY"�A�}�l�N�t���边��ѡA�í��s�զX...\n"+
                            "�g�L�@�f�V�O�A�A�զX�X"HIC"�t���边���C��--��q...\n"NOR);
            me->receive_damage("mp",200);
            sword=new_ob(__DIR__"../wp/ds_sword"); 
            sword->move(me);
            destruct(obj);
            return 1;
            }
       default: write("�S���o�ث��A�C\n");
                return 1;
       }
}
else
{
  write("�A���k�O�����H�Ұ��ܫ����O�q�C\n");
  return 1;
}
}

