#include <ansi.h>
inherit NPC;
int ask_me();
string* goods = ({
       __DIR__"obj/shoujuan",
       __DIR__"obj/yangpi",
       __DIR__"obj/madao",
       __DIR__"obj/shoujuan",
       __DIR__"obj/shoujuan",
       __DIR__"obj/shoujuan",
       __DIR__"obj/jiunang",
       __DIR__"obj/shoujuan",
});
void destob(object ob);
void create()
{
        set_name("Ĭ��", ({ "supu"}));
        set("gender", "�k��");
        set("age", 21);
        set("long", "�@�Ӧ~�������ħJ���ϤH, ���ħJ�Ĥ@�i�hĬ�|�J����l�C\n");
        set("attitude", "heroism");
        set("level", 25);
        set("inquiry", ([
            "����" : "���ҬO�ڪ��ߤW�H�A�ڨC�����F���T���|�e�o�T�֡C\n",
            "����q" : "�o���q�۱o�̦nť���F�A���H���o��ѹa���۱o�٦n�C
���o�X�~�ӡA�ڤ@���Sť��o�ۺq�A�@���S�b����o�C\n",
//            "�L��" : (: ask_me :),
 //          "���" : (: ask_me :),
            "�p�ݷ�" : "�N�O�p�ѤH�ڡA�L�|�C�S���S�P�����s�A�|����ϰ��Ǫ��e�f�C\n",
            "Ĭ�|�J" : "���O�ڪ��R�A�O���ħJ�ڪ��Ĥ@�i�h�I�����I\n",
        ]) );
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
"Ĭ���ۻ��a�W�D: �ڤ]�n�ǧڪ��R�������ħJ�Ĥ@�i�h�C\n",
"Ĭ���ۨ��ۻy: �q����h�ˤ@�i�W�����T�֡A�e�����ҩO? \n",
        }) );
        carry_object(__DIR__"obj/wandao")->wield();
        carry_object(__DIR__"obj/yangao")->wear();
        carry_object(__DIR__"obj/jiunang");
}
