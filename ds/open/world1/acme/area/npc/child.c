#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�p�Ĥl" , ({ "child" }) );
        set("level",1);
        set("race","�H��");
        set("gender","�k��");
        set("dex",-1);
        set("age",6);
        set("long","�L�O�@�ӥ���ż�������p�ġC\n");
        set("inquiry/�p��","�@�H�A�O���W���A�ڭ̲ժ��������ҥh���a��ܡH\n");
        set("inquiry/��","�o���p���N�b�M�g�Ҧb���a��A���U�A�٬O�O�h�n�F�A���Y�������I�C\n");
        set("inquiry/�O","�o���p���N�b�M�g�Ҧb���a��A���U�A�٬O�O�h�n�F�A���Y�������I�C\n");
        set("inquiry/�L��","�o�L�ͮ��Ʒ��F�A���H�N���A���ٮt�I�����O....@_@\n");
        setup();
        carry_object(__DIR__"wp/sword1.c")->wield();
}

