inherit ITEM;
#include <ansi.h>

void create()
{
  set_name(HIC"������"NOR, ({ "hao tian mirror", "mirror" }));
        set_weight(2000);
        set("long",@LONG
����j�p�i�L�A���O�j�ɩҨ�A�ø񴳴��A�ݰ_�Ӧ~�N�[���C�譱��
�իժ��A�H���b�����]������X�v���A���O��l�٤��p�����ӵL����
�¬}���T�ǡC�I���f��F�ǹ����B�@�˪��j�Ǥ�r�A�]�����D�O��
��H�b�ƻ�ɥN�ˤW�h���A�ϥ��o��l�]���N�z�X�F�����P�A�̥ʤ]
���D�o�˪��F��O�_���C
LONG
);
  if( clonep() )
    set_default_object(__FILE__);
else
  {
   set("unit", "��");
    set("no_sell", 1);
    set("no_sac", 1);
    set("no_give", 1);
}
  setup();
}

void init()
{
  add_action("do_use","use");
}

int do_use()
{
  object z,me,env;
  me=this_player();
  env = environment(me);
  if(!objectp(z=present("mirror",this_player()) ) )
    return notify_fail("�A�S���F��i�H�ϥΡC\n");
  if( me->is_fighting() )
    return notify_fail("�A���b�԰����A�L�v���ߡC\n");

message("world:world1:vision",
HIY"\n"+me->query("name")+""NOR+HIW"�y�y�M���}�f�G�u"NOR+WHT"�ڷQ���D�C�C�C"NOR+HIW"�v\n\n"NOR
        ,users() );
       call_out("quest1",4);
  return 1;
}

void quest1()
{
        message("world:world1:vision",
WHT"\t\n�y���h���H�M���۪��H�A�s���O�֡C�C�C����d�ˡH�z\n"NOR
        ,users() );
       call_out("quest2",3);
        return;
}

void quest2()
{
        message("world:world1:vision",
WHT"\t\n�y��Ѫ��H�M�O�o���H�A�s���O�֡C�C�C����h�W�H�z\n"NOR
        ,users() );
       call_out("quest3",3);
        return;
}

void quest3()
{
        message("world:world1:vision",
WHT"\t\n�y���ݪ��H�M���ݪ��H�A�s���O�֡C�C�C��������H�z\n"NOR
        ,users() );
       call_out("quest4",3);
        return;
}

void quest4()
{
        message("world:world1:vision",
WHT"\t\n�y�Q���_�Ӫ��H�M�Q�o�_�Ӫ��H�A�s���O�֡C�C�C����֬��H�z\n"NOR
        ,users() );
       call_out("quest5",3);
        return;
}

void quest5()
{
        message("world:world1:vision",
WHT"\t\n�y�Ҧ��H�M�Y�ӤH�A�s���O�֡C�C�C������n�H�z\n"NOR
        ,users() );
        return;
}

