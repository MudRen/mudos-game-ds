#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�Q",({"ba"}) );
        set("long","�@���Q�C\n");
        set_weight(100);
        if (clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","��");
                set("value",100);
        }
        setup();

}

void init()
{
        add_action("do_test","testba");
       add_action("do_show","show");
}

int do_test(string arg)
{
        object me,target;
        string msg;
//      target=find_player(arg);
//      if(!target) return notify_fail("�S���o�ӤH�C\n");

        me=this_player();

msg=@LONG
                                                /|\n
                      /|  /|                  ,^^^--_/|\
                  _-^^^^^^-_/|          ._---;/^ ^   `./|
           v     /^^ v  ^^  ^/|         (( );/^     > > `/|
     \    (:)   /^ ^(:)  ^  >>`/|          ,/ ^^  >    > >`/|
      \   (::) /   (::) ;> / >>`/|        ,/^^^   ,-.   > >>`/|
       \  (::),^^^.(::)/`/   >>>`/|      ,/^^   ^;   `.   > >`/|
        \ <_):::::(_>/ /`._--.  `/|     ;/^  ^  ;-_.  `.. >  >`/|
         \ \|:::|:::|/ /   ( ))  >`/|   ,/^ ^   ;( ))     ;  >> `/
          \  \_:|:_/  /    `.     >`/| ,/^^   ^ ;          ;>  > /;
           \ \@, .@/ /      `.  > > `-- ^^    $
            \ \=:=/ /       _`.    >  > >  >  ;           ,` >  /;
             \\=:=//       ((,`.> >    > > _/           ,' > > /,
         _    <o_o>           ^`-__ > ___-^          _,' >> /;
  ^^-__ /^^\ _-                     ^^^^^_-^=--^^ >>$
    ^^-|  ';|__-^^^-___                   _^_^--____$
   ___-_\__/--^^^                          ^^^
 ^^ ^^^
LONG;

msg+="$N���o�X�L�a�L�ɪ�"+ HIW "���y�Q�z����" +NOR "�A"+GRN"�ٮɤѦa�Ƭ��L�ɪ��·t"+NOR"�A�@��"+ HIR "�F�z"+ arg+NOR "�I�I\n";

                if ( me->query("str") > 20 )
                         msg+= "�Ѫŵn��" + GRN  "�ª����`������" + NOR "�A$N�@���n�R���g�Q�@���A�ߨ��"+arg + HIR "�F�z" + NOR "�I�I\n";
                else
                         msg+= HIR"$N���E�F�ӱj�j���O�q�A�H�P�X�ۥ��ǡA��"+arg+"�{�L�h�C\n" NOR;

              message_vision(msg, me);

        return 1;
}

int do_show()
{
        message("world:world1:vision",
     HIW "�ѲP�R�C��(King)�Q�y�v���o��z���A�q�������b�o�ӥ@�ɤW�F�I�I�C\n" NOR

,users() );

return 1;
}
