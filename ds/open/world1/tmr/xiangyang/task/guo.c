// Last Modified by Sir 2003.11.12
// guojing.c ���t

inherit NPC;
#include <ansi.h>
inherit __DIR__"gysjob.c";  //�q�h����
inherit __DIR__"teamjob.c"; //���I�l�ӥ���
inherit __DIR__"scjob.c"; //�u������

void create()
{
	set_name("���t", ({"guo jing", "guo", "jing"}));
	set("nickname", HIY"�_�L"NOR);
	set("gender", "�k��");
	set("age", 41);
	set("long", 
		"�L�N�O�H�٥_�L�����t�A�J�O�X�j���N�䦽�����M�t���A�S�O\n"
		"���n�C�ǡB���u����ౡB�u�_���v�x�C���M�u�ѹx���v�P�B�q\n"
		"���H���{�̡A���ݼƪ��Z�\�C�L���ۤ@��Ǧ���T�A��A���A\n"
		"���p�����ؤ��z�X�@�ѫ��Y�C�O�H���ѱo���ͤ@�Ѵܨؤ����C\n");
	set("attitude", "friendly");
	set_max_encumbrance(100000000);
	set("per", 20);
	set("str", 40);
	set("int", 20);
	set("con", 30);
	set("dex", 25);
	set_temp("no_kill",1);
	set("no_get",1);
	set("chat_chance", 3);
	set("chat_msg", ({
		"���t�ĤF�f��D�G �X�j�L�[���������U�A�@�w�|�A�X�ޭp�A�T��S���b����A�o....\n",
		"���t���D�G�غ夽�D��Ӥ����i�n�A��Ť@�w�n�^�j�z�h�ݬݦo�C\n",
//		(: random_move :),
	}));
	set("inquiry", ([
		"�P�B�q" : "�A����کP�j���F�H�L�{�b�i�n�H\n",
		"�ѹx��" : "�P�j���@�e�o�ˡA�S�I���g�I\n",
		"�x�C��" : "�v�����F�Y�A�N�O���w���C��B���A�٬O���F��Y���C\n",
		"���Įv" : "���O�ڮ��s�j�H�C�L���C�|���A���s�������������C\n",
		"�@�O�j�v" : "�b�U��j�v�n�ͷP�E�C\n",
		"�ڶ��W" : "�o�ӦѬr���A�`���ڤ���v���A�@�������ƤF�A�M���P�L�F��C\n",
		"���T"   : "�T��O�ڪ��R�d�A�A�ݦo���ơH\n",
		"�T��"   : "�T��N�O�T��F�C�A�ݳo��h�F���H\n",
		"����"   : "�o�Ӥk��A�S�¤S��ť�ܡC\n",
		"����"   : "����ͩ�å@�A�o���l�S�h�}ˮ�C���@�o��ּ֤@�@�C\n",
		"���}��" : "���O�ڪ��p��l�C\n",
		"���L"   : "�L��T�꦳�X���C\n",
		"���"   : "���D����ڦ��b�v���ˡC\n",
		"�C�B��" : "���D���q�����ѡA�O�u���ǡC\n",
		"�_��c" : "���O�ڤj�v���C\n",
		"���o"   : "���O�ڤG�v���C\n",
		"���_�s" : "���O�ڤT�v���C\n",
		"�n�Ƥ�" : "���O�ڥ|�v���C\n",
		"�i����" : "���O�ڤ��v���C\n",
		"�����v" : "���O�ڤ��v���C\n",
		"���p��" : "���O�ڤC�v���C\n",
		"����"   : "�����^���X�ʦ~�F�A�u�������h���F�L�̡C\n",
		"���v"   : "�{�b�X�j�H��������A�ڭ����߱����{�ڡI\n",
		"job"    : (: ask_job :),
		"�q�h"   : (: ask_job :),
		"�l��"   : (: ask_jianxi :),
		"�u��"   : (: ask_shoucheng :),
		"job2"   : (: ask_shoucheng :),
	]));
	set("qi", 8000);
	set("max_qi", 8000);
	set("jing", 8000);
	set("max_jing", 8000);
	set("neili", 24000);
	set("max_neili", 24000);
	set("jiali", 500);
	set("combat_exp", 25000000);
	set("score", 200000);
	set_skill("force", 400);		// �򥻤��\
	set_skill("huntian-qigong", 400);	// �V�Ѯ�\
	set_skill("unarmed", 400);		// �򥻮��}
	set_skill("xianglong-zhang", 400);	// ���s�Q�K�x
	set_skill("dodge", 400);		// �򥻸��{
	set_skill("xiaoyaoyou", 400);		// �p���C
	set_skill("parry", 400);		// �򥻩۬[
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");
	prepare_skill("unarmed","xianglong-zhang");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	::init();
	add_action("job_over","shoucheng");
}
