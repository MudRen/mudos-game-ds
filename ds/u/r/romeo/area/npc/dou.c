#include <ansi.h>
inherit NPC;
void create()
{
set_name("��", ({"dou"}) );
set("long","�b�A�e���o��Z�̨Ӧۦa���A�G�Q�~�e���F�l�D�̱j���D�A�N
�N�F��浹�F����ù�A���F���Ϫ̡A�L���N���N�s�G���C\n");
set("attitude", "aggressive");
set("level",40);
set_skill("dodge",90);
set_skill("blade",100);
     set("title",HIC"����ù"NOR);
set_skill("unarmed",90);
setup();
carry_object("/u/k/king/area/npc/wp/blade2")->wield();
}
