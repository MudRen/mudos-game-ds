#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�W�x�b",({"killer",}));
 set("long","             �A�ݤF�@�ݲ��e���ѤH,��b�L�k�Q���L������@�� , �o�ӦѤH��
             �M�ثe�H�g�C�Q�C���F, ���L�L�������ϦӮg�X�@�ѥO�H�`�Ȫ���
             ��, ��ӥL�N�O�T�Q�~�e�W�_���򪺦��W����--��C���� �W�x�b! 
             �u�O�H�۷���y��, �L�������P��Ѵ�, ��ϵ��R���ٱo��ʧ���
             , �L�N�����ŧi�h��, �åB���ٸ����夣����, �o�����ܩ�L��
             �k, �Ө�^���ӮĤO.\n"
    );
 set("attitude","peaceful"); 
 set("age",67);
 set("gender","�k��");
 set("level",30);
 set("title",HIY"�夣����"NOR);
 set_skill("unarmed",55);
 set_skill("sword",80);
 set_skill("force",60);
 set_skill("parry",70);
 setup();
 carry_object(__DIR__"eq/longsword")->wield();
 carry_object(__DIR__"eq/cloth")->wear();
}
