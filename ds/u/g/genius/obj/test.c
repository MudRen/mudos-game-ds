#include <ansi.h>
inherit ITEM;

void create()
{
       set_name(HIW"�ܺA����"NOR,({"pill"}) );
        set("long","LONG");
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {  set("unit", "��");
                set("value",50000); }
setup();
}

void init()
{
     add_action("do_eat","eat");
}

int do_eat(string arg)
{
       object me = this_player();
       object ob = this_object();

       if( !this_object() ) return 0;        
       if( !this_object()->id(arg) ) return 0;
       me->set("env/msg_mout",CYN"\n$N���ۥj�Ѫ��G��A��M�b$N�����e�X�{�F�@�D�t�v���A$N���F�i�h�A�������L�v�L�ܡC\n"NOR);
       me->set("env/msg_min",BLU"\n�@�}�������G�y�q����ǥX�A��M�@�}�Ǽv�ƹL�A������G�h�F�@�ӤH�C\n"NOR);
       me->set("env/msg_clone",HIY"$N"HIY"�L���a���ۡG"HIG"�u�e�e��$n"HIG"�{����v"HIY"�A�A�����e���M�X�{�F�@��$n�C\n"NOR);
       me->set("env/msg_dest",HIY"$N"HIY"�j�s�G"HIR"�u�h�h��$n"HIR"����v"HIY"�A�A���e��$n"HIY"���M�����b�Ů𤤡C\n"NOR);
       write(".....&^#@(&)*#@$@#&.....\n"NOR);
       destruct(ob);
       return 1;
}

