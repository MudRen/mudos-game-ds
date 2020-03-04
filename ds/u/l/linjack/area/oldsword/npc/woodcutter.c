#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�Ѿ���",({"special woodcutter","woodcutter"}));
 set("long","�o�������M���w�g���Q�n�X�F, �i�O�B�_��ӻa�l���O\n"
            "�ӥB�������ġB��������, �����O�Ӥ@��b��㪺����,\n"
            "�A��ı�o�L�i��O���w�h�����򪺦ѫe��.\n");
 set("attitude","peaceful"); 
 set("age",67);
 set("gender","�k��");
 set("combat_exp",124753+random(38358));
 set("level",45);
 set("title","���򯫾�");
 set_skill("unarmed",55);
 set_skill("axe",85);
 set_skill("blade",65);
 set_skill("force",85);
 set_skill("parry",70);
 set_skill("cloudmove",90);
 set_skill("slash-wood",85);
 map_skill("dodge","cloudmove");
 map_skill("blade","slash-wood");
 map_skill("axe","slash-wood");
 // �]�w�ݩʤ��t��, �C�@�����Ȧb�t9�ܥ�10����
 // �ӥB�|�����`�M�n��n���� 20			by shengsan
 set("guild_gifts",({10,4,0,6}));
 set("chat_chance",20);
 set("chat_msg", ({"�Ѿ��Ү��_�⤤�����Y, ����W��h.\n",
                   "�Ѿ��Ү��ۤ⤤���Y, �����D�b��e����.\n",
                   (:command("sweat"):),
 }));
 set("chat_chance_combat",200);
 set("chat_msg_combat",({(:command,"exert slash-wood cross-slash":),
                         (:command,"exert slash-wood all-slash":),
                         (:command,"exert cloudmove ghostmove":),
                         (:command,"say ��n�H���Ѧ��n��!!":),
 }));
 set("inquiry/name","��--��--��, �ѤҦ��H�b�s�L�h�~, ���H���s�ڰ��򯫾�! �ڳs�ۤv�m���򳣧ѤF...\n");
 set("inquiry/axe","�o����Y, ��F�Ѧ��|�Q�h�~....��F, "HIY"���Ǩ�"NOR"�N���n�A���F...\n");
 set("inquiry/���Ǩ�","���O�i�D�A���n�A���F��?");
 set("inquiry/where are you come from","�Ѧ��O�o�̤H! �ڦb�o��F�|�Q�~, ���M�O���̤H?");
 set("inquiry/�A�O���̤H","�Ѧ��O�o�̤H! �ڦb�o��F�|�Q�~, ���M�O���̤H?");
 setup();
 carry_object(__DIR__"eq/lumber_axe")->wield();
 carry_object(__DIR__"eq/cloth")->wear();
 carry_object(__DIR__"eq/sandels")->wear();
}
