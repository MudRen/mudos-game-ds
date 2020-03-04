#include <ansi.h>
#include <path.h>

inherit NPC;

void create()
{
    set_name(HIW+BLK"�˦Q���ѤH"NOR, ({ "oldman","man" }) ); 
    set("long","�޲����ѤH\n"NOR);
    set("level",1);
    set("age",500);
    set("gender", "�k��"); 
    set("race", "human");        
    set("no_fight",1);
    setup(); 
    this_object()->set_temp("define_look"," �a�Q�b��");
}

void init()
{       
    object me;
    ::init();
    if( interactive(me = this_player()) && !is_fighting() )
    {
       remove_call_out("meeting");
       call_out("meeting",6,me);
    }
}

void meeting(object me)
{
    object mob;
    mob = this_object();

    if(!me || environment(me) != environment()) return;
    if(!me->query("level") <30)
    {
       message_vision("\t$N���G�o��"+RANK_D->query_respect(me)+"�A�o�̬O�q�����תŶ����J�f�C\n",mob);
       message_vision("\t$N���G�ڧi�D�A�A�i�J��i�O�L�k�A�^�Y�����I\n"NOR,mob);
       message_vision("\t$N���G�A�O�_�n�i�J���B�H ["HIY"say �i�J / ���}"NOR"]\n"NOR,mob);
    }
    else
    { 
       message_vision("$N���$n���G�A�S�����i�h�̭��C\n",mob,me);
    }
//    call_out("leave",100,mob);
    return;
}

void relay_say(object me, string str)
{
    object mob;
    mob = this_object();

    if( !userp(me) ) return;
    if( me->is_busy() ) return write("�A���b���C\n");
    if( strsrch(str,"�i�J") != -1 )
    {
       if(me->query("level") <25)
       {
          message_vision("$N���G�ڤ������z�եեh�e��...�٬O�Ц^�a�C\n",mob);
          return;
       }
       me->start_busy(4);
       mob->set("info",1);
       call_out("msg",1,me,mob);
       return;
    }

    if( strsrch(str,"���}") != -1 )
    {
       message_vision("$N���G�o�ˤl�r...�����A�ǳƦn�F�A�ӧa�C\n",mob);
       message_vision(HIR"[�@�ѤO�q�N�A�������f�C]\n"NOR,me);
       me->start_busy(3);
       me->move("/u/f/fedex/room3");
       return;
    }
    return;
}

int msg(object me)
{
    int i;
    object mob;
    mob = this_object();
    i = mob->query("info");
    switch(i)
    {
       case 1:
            message_vision("\t$N���G�ݼˤl�A�w�g�ǳƦn�F�C\n\n",mob);
            mob->set("info",i+1);
            call_out("msg",2,me);
            break;
       case 2:
            message_vision("\t�u��$N�L�̰�ᦳ��A�������o��⪺���~�C\n\n",mob);
            mob->set("info",i+1);
            call_out("msg",3,me);
            break;
       case 3:
            message_vision(HIG"�ƹD���~�����N$N�]��C\n"NOR,me);
            me->move(__DIR__"../room2");
            tell_room(__DIR__"../room2",HIG"�ƹD���~�{�L�L�A"+me->query("name")+"�X�{�b�o�̡C\n"NOR);
            mob->delete("info");
            destruct(mob);
            break;
    }
    return 1;
}
/*
void leave(object mob)
{
    message_vision("$N��M�����b�A�����e�C\n",mob);
    destruct(mob);
    return;
}
*/
