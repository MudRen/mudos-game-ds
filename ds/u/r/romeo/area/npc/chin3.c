#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���l��", ({ "ghost shu huang chin","chin" }) );
        set("level",65);
set("long","�b�A���e���O�����j�W���@�N�������l�ӡA���F�@�ΤѤU�������Q�Ѳz�}�_�ɪ�
�A�ե��n�гy�@�Ӧ����@�ɡC\n");
;
        set("age",300);
        set("evil",99);
     set("title",MAG "����"NOR);
        set("gender","�k��");
        set("attitude","killer");
        set_skill("staff",100);
        setup();
        carry_object("/u/k/king/area/npc/wp/stafff")->wield();
        carry_object("/u/k/king/area/npc/eq/devil-armor")->wear();
}
void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }
        message("world:world1:vision",
HIC"\n  �������H���֪��t�צ^��:"HIW"\n\n\t�@�N�����Я��l�Ӧ��b"+ob
->name(1)+"���⤤�F�A�S�Q�ʦL�줭�D���������C\n\n"+NOR
        ,users());
        ob->add("popularity",1); //�n��
     message_vision( "$N"+HIR "�{���e�A�κɤ��O�N�ۤv���]����H" NOR ,this_object()
);
        ::die();
        //destruct(this_object());
        return;
}

