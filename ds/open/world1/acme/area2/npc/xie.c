/* write by -Acme-
   update by -Acme-
*/

#include <ansi2.h>
inherit NPC;
void create()
{
    set_name( "�Ѵݨ���", ({ "tan chan xie","tan","chan","xie", "__GUARD__" }) );
    set("level",65);
    set("combat_exp",5500);
    set("evil",99);
    set("long", @Long
�L�O�խߦa�������j�ѡA�L�j�Y�ѯ��A���i�@�@�A�L�P�����H�h
�������A�q����A�g�L�L�ƪ��j�p�Ԫ��A�ԵL���J�A�L�w����
�Z�L�����Q�D�A�����H�h��L���ᬰ�Ҽ��A�\�h�ۦ��@�檺�x��
�H�A�v��۪��{�A�ӳ�ӫխߦa���A�o���o�Ͱ��L�s�C
Long);
    set("age",100);
    set("gender","�k��");
    set("title",HIR"�i�խߴc���j"NOR);
    set("Merits/wit",0);
    set("int",40);
    set_skill("sword",110);
    set_skill("dodge",110);
    set_skill("parry",110);
    set("talk_reply","�����F�A�u�n�A���h�ʧڪ����_�N��F�I�ڥͥ��̫�H�ðʧڪ��_���F�C\n");
    set("inquiry/���_", "��I�ڪ����_�i�h�F�A���I�ڤ�W�o���ѥi�O�ڦ����_�����̳߷R�F�C\n");
    set("inquiry/�_��", "��I�ڪ����_�i�h�F�A���I�ڤ�W�o���ѥi�O�ڦ����_�����̳߷R�F�C\n");
    set("inquiry/��", "�o���ѥi�O���������B���A�W�Y�g���i�աj�r�i���O�j�j�����K�C\n");
    set("inquiry/��", "�ڬݧA�o�p�٤l�Z�������A�ڴN��A���a�I\n"
                      "              �A�i�H�b�԰����ۤߪ��q��۫�(you)�A�i\n"
                      "              �H�o�X��H���¤O�@�I�I\n",
    );
    set("chat_chance_combat",80);
    set("chat_msg_combat", ({
        (:command("you"):),
        (:command("say �A�o�c��A���ڳo�@�ۡA�����a�I�I�I"):),
    }) );

    setup();
    set_living_name("__XIE__");
    carry_object(__DIR__"wp/darksword.c")->wield();
    carry_object(__DIR__"obj/book.c");
    carry_object(__DIR__"obj/bone.c");
}

void init()
{
    ::init();
    add_action("do_guard", "go");

}

int do_guard(string arg)
{
    object me;
    object obj;
    me=this_player();
    obj=this_object();
    if( (arg!= "southwest") || !this_player()->visible(this_object()) ) return 0;
    write( name() + "�N�A�d�F�U�ӡC\n");
    command("say �x�I�H�p��I�I�Q���ڪ����_�ӵۡI�H");
    command("say �A�֨��a�I�U���O���ڨ���A�A�_�h�I���I�I�I");
    obj->kill_ob(me);
    return 1;
}

void die()
{
    object ob;

    if( !ob = query_temp("last_damage_from") ) ob = this_player(1);

    if( !ob ) {
        ::die();  return;
    }

    message("world:world1:vision",CYN"\n  �Z�L�ǥX�F�@�h��H������:\n\n\t�u�խߴc���v�Ѵݨ��вש�ѵ��F"+ob->name(1)+"�C\n\n"+NOR,users());
    ob->add("popularity",3); //�n��
    ::die();
    return;
}
