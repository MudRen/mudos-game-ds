// By Tmr 2002/05/07
// Quest skill:�k���B���� ��C�k ��X�t��(�C��) sk point 4
// �����ƪ��p��...
// 
#include <npc.h>
#include <skill.h>
#include <ansi.h>
inherit F_VILLAGER;
void do_ask(object me);
void create()
{
        set_name("������", ({ "jiang yu huo","jiang","huo" }) );
        set_race("human");
        set("title","����");
        set("age", 60);
        set("long",@LONG
�������O�o�����������A�@�L���y�����A���Y�Q�ª��Y�v�M��M����
�������A�b�b���H�����]���L���ڪ��~���ӻ����L�C
LONG
);
        set_skill("sword",80);
        set_skill("secondhand sword",80);
        set_skill("isolate sword",90);
        set_skill("campaign sword",90);
        map_skill("sword","isolate sword");
        map_skill("secondhand sword","campaign sword");
        map_skill("parry","campaign sword");

        set_skill("parry",60);
        set_skill("dodge",80);
        set("chat_msg", ({
                (: command("sigh") :),
                (: command("say ���r..�ڨ��p�]�l�q�Q�ѥX�h���A���M�N�S�A�^�ӤF�A�u�O�H��ߧr�C") :),
        }));
	set_attr("emit",50);

        setup();
        set_level(20);
        carry_object(__DIR__"obj/drift-cloud-sword")->wield("secondhand sword");
        carry_object("/d/obj/shortsword")->wield("sword");

}

