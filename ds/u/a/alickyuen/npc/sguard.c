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
                set_skill("unarmed", 100);
	setup();
carry_object( __DIR__"wp/moongun.c")->wield();
carry_object("/u/w/wilfred/item/box");

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
