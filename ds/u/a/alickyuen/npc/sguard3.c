#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIR"�i�f�i��-�O��"NOR, ({ "CocaCola","guard" }) );
	set("long", "�o�O�t�d�i�f�i�֤j�H�w��������H�C\n");
	set("race","�����H");
	set("age", 100);
	set("level", 50);
                set("max_hp", 1000);
                set("chat_msg", ({
  HIY"�O�߻��G�S�ƪ��N�֨���C\n"NOR,
}));
                set("chat_chance_combat", 14);
                set("chat_msg_combat", ({
 HIY"�O�߻��G�ϤF�ϤF�A���M�Q���i�f�i�֤j�H���D�N?!�����a\n"NOR,
  HIY"�O�߻��G�i�f�i�֤j�H�A��L���F�a\n"NOR
}));
        set("amount",1);
        set("ridable",1);
                set_skill("unarmed", 100);
	setup();
carry_object( __DIR__"wp/moongun.c")->wield();

}
void init()
{
        object leader;
        if( objectp( leader = find_living("alickyuen") ) )
        {
                set("creater",leader);
                set_leader(leader);
                return;
        }
        ::init();
}
int ride_before_action(object me)
{
        object ob=this_object();
        message_vision("�@"+this_object()->name()+"�s�C���A$N���W�F"+this_object()->name()+"���I�W�C\n",me);
        return 1;
}

int ride_after_action(object me)
{
        message_vision("�@"+this_object()->name()+"���b�I��$N�C\n",me);
        return 1;
}

int ride_off_action(object me)
{
        message_vision("$N�q"+this_object()->name()+"���I�W���F�U�ӡC\n",me);
        return 1;
}
