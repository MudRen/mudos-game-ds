#include <ansi.h>
inherit NPC;
void create()
{
set_name(HIR "����ͧ�" NOR, ({"devil-ree"}) );
  set("long","�o�����Ǭݰ_�Ӥ@������A�Q�������c�A���]�O�o����\n"
  "�����Y�Ѥj�A�S���٬O���n�S�쥦����C\n");
set("attitude", "aggressive");
set("level",25);
set_skill("dodge",60);
set_skill("unarmed",60);
setup();
carry_object(__DIR__"obj/pearl");
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
HIC"\n  ���]�ӥH���֪��t�צ^��:"HIW"\n\n\t�W�j�]���о԰�ӳ��Q"+ob
->name(1)+"���}�F�C�Z���N���J�@�����I�C\n\n"+NOR
        ,users());
        ob->add("popularity",0); //�n��
        ::die();
        //destruct(this_object());
        return;
}

