// ���ܥ@�ɡO���O�O�������D����
/* <SecCrypt CPL V3R05> */

// worker.c

inherit NPC;
#include <ansi.h>

void create()
{
        set_name(HIR"�C��j�n��"NOR, ({"ds speaker"}));
        set("gender", "�k��" );
        set("age", 13);
        set("title", HIC"�j�n���x���H"NOR);
        set("nickname", HIG"�L�����n���H�F���H"NOR);
       set("long", "�N��Promise�o���@���L�Q����!!\n");
       set("no_kill",1);
       set("no_fight",1);
       setup();
       remove_call_out("msg");
        call_out("msg",60);
}

void msg()
{
       message("world:world1:vision","�i"HIY"�C��j�n��"HIW"���i"NOR"�j�G"NOR"�Ѫ��a�h�h���U�s�Ӫ��a�A�O���L�̳B��L�H�D�U���ҬɡI�I\n"NOR,users());
      
       remove_call_out("msg");
       call_out("msg",600);

}


