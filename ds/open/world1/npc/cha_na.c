#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�b��", ({ "cha na","na" }) );
        set("race","human");
        set("gender", "�k��");
        set("level",33);
        set("age",37);
        set("evil",15);
        set("attitude", "aggressive");
        set("title",HIR"�t���D��"NOR);
        set("long",@LONG
�t���Ϫ̤��̨��c�A�̴ݼɪ��@�H�A���ƥu�̦ۤv���ߦn�A
�q���Ҽ{�L�H�A�ݱ����ʡC�����]�X�ͮɴN�M�F�A�]���@��
�Υ��]�ۡA�γ\�ѥͪ��ݻ٬O�ɭP�L�ʮ氾�t����]�C
LONG
);
        setup(); 
        carry_object(__DIR__"../eq/ys_helmet")->wear();
        carry_object(__DIR__"../eq/fk_gloves")->wear();
}

