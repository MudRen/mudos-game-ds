#include <ansi.h>
inherit NPC;
void create()
{
set_name(HIY"���泾"NOR, ({ "chocobo" }), );
set("age",5);
set("level",10);
set("long","\n�@��H�Ū����q���泾�C�j�Ӧ��O�����}����@���O�O����V����˪L�M���C\n");
set("ridable",1);
set("ride_type","Ground");
set("chat_chance", 15);
set("chat_msg", ({
HIY"���泾"NOR"["HIW"�B..�B.."NOR"]���s�F�@�n�C\n",
HIY"���泾"NOR"�R�R�μL�ھ�z��"HIY"�Ф�"NOR"�C\n",
HIY"���泾"NOR"�j�j���������n�_���ݵۧA�D�D�D\n",
}));
setup();
}


