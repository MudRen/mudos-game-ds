#include <ansi.h>
inherit NPC;
void create()
{
set_name(HIR "����ͧ�" NOR, ({"devil-ree","ree"}) );
  set("long","�o�����Ǭݰ_�Ӥ@������A�Q�������c�A���]�O�o����\n"
  "�����Y�Ѥj�A�S���٬O���n�S�쥦����C\n");
set("attitude", "aggressive");
set("level",25);
set_skill("dodge",60);
set_skill("unarmed",60);
setup();
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
HIC"\n  ����l�ĹD�G"WHT"\n\n\t�Q����E�ׯ��]�Q"+ob
->name(1)+"���}�F�C"HIR"\n\n\t�@�H�ְ֧k�R�a�I�I�I\n\n"+NOR
        ,users());
        ob->add("popularity",0); //�n��
        ::die();
        //destruct(this_object());
        return;
}
