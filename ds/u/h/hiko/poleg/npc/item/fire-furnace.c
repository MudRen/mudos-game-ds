/*���ɮ׬O�ѷ�kkeenn ��lovecity furnace*/
#include <ansi.h>
inherit ITEM;
void create()
{
  set_name(HIM"���l"NOR,({"fire furnace","furnace"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {

    set("long",@LONG  
    �o�O�M�������w�ۤv�ʤ�@�Ʋz���H�ҩ�m������A�i�H
�̭ӤH�ߦn�ӥ[�J�Ʋz�A�ӥB�N�k�h�ܡA�O�\�h�Ӧ������H��
�̷R�A�]�O�ӳo�̪��H�`�ϥΪ��@�ؤ覡�A�������ūפQ���A
���B�㦳�}�n�j�����I�A�i�H���O�p�Ъ��̨ΥΨ�A�ڻ��O��
�D�q���a�^�Ӫ��A�i�H���O�b����w�g���L�Ȧ��A��Ź�̳�
���R�󦹹D�A�i�����l�����Z�C
( �ϥΤ�k: cook)
LONG
);
 }
  set("no_sac", 1);
  set("no_get", 1);
  set("no_clean_up",1);
  set("value", 300);
  set_max_encumbrance(999999);
  setup();
}

void init()
{
  add_action("do_cook","cook");
}

int do_cook()
{
  object ob = this_object(), *obs,me;
  me = this_player();
  obs = all_inventory(ob);
       if (me->query("ap")<40)
                return notify_fail ("�A����O���������믫�@�Ʋz�F��!");  
       if (me->is_busy())
                return notify_fail ("�A���ʧ@�٨S�����I\n");
        if( !sizeof(obs) ) 
                return notify_fail("�S���F��b���A��˵N???\n"); 
        if (ob->query_temp("make_food")>0)
                return notify_fail ("���l���H�b�ϥΤF�I\n");
                ob->set_temp("make_food",1);
   message_vision(HIW "$N��Ʋz�B�z�n�A�������G�_�۾ĵo�����A���t���}�l�ʤ��\n\n" NOR, me);
        tell_object(me, HIW "����ǳƦn��A�H�Y�N�}�l�j�㨭��i�{�p���F.....\n\n" NOR );
        tell_object(me, HIY "��������������Դ��Դ����\n\n\n" NOR );
        me->disable_player_cmds("�A���b�@�Ʋz�C\n");
        me->set_temp("is_busy/making","�A���b�@�Ʋz�C");
        me->start_busy(10);
        call_out("make1",3,me);
        call_out("make2",8,me);
        call_out("makefood",15,me);
        return 1;

}
 void make1(object me)
{
        if(!me) return;
    tell_object(me,HIG"�A�����i�J�F���p�A�@�Ʋz�V�ӶV����F��\n"NOR);
        me->add("ap",-20);
        return;
}

void make2(object me)
{
        if(!me) return;
        tell_object(me,HIB"�A��ۤv�������Z���N�Aı�o�ۤv�i�H����p�v�F���C�C�C\n"NOR);
        me->add("ap",-20);
        return;
}
int makefood(object me)
{ 
  object ob = this_object(), *obs;
  int i,n,x,index = 0;
  me = this_player();
  obs = all_inventory(ob);
 for(i=0;i<sizeof(obs);i++)
  {
    if(obs[i]->query("id") == "sifu meat") index += 13;
    if(obs[i]->query("id") == "liuye meat") index += 14;
    if(obs[i]->query("id") == "sandling meat") index += 15;
    if(obs[i]->query("id") == "shark meat") index += 16;
    if(obs[i]->query("id") == "yue meat") index += 18;
    if(obs[i]->query("id") == "grig meat") index += 20;
    if(obs[i]->query("id") == "flyfish meat")  index += 21; 
  }
  
  if(random(10) > 4)
    {
        switch(index) 
        {
        case 28..41 :                      
     message_vision("$N�b�Ӳӽը����U�A�@�X�F�@�D"+ HIY"�������L"NOR +"�C  \n",me);
                           me->add("ap",-30);
                           new(__DIR__"food/shugin-pinpan")->move(ob); 
                           break;
        case 42..57 :
        message_vision("$N���O�M�㭹�Ф���A�@�X�F�@�D"+ HIY"�T���]��"NOR +"�C  \n",me);
                           me->add("ap",-30); 
                           new(__DIR__"food/sanwe-jinin")->move(ob);                           
                           break;
                       
        case 58 :                           
        message_vision("$N�ΥX�F�a�ǯ���A�@�X�F�@�D"+ RED"���N�}�L��"NOR +"�C \n",me);
                           me->add("ap",-40);
                           new(__DIR__"food/hungsa-tantsu")->move(ob);
                           break;
        case 59 :
        message_vision("$N���O��s�U�A�����@�D"+ RED"�»�����"NOR +"\n\n",me);
                           me->add("ap",-40);
                           new(__DIR__"food/malain-pan")->move(ob);
                           break;
        case 63 :
        message_vision("$N���ߧ�J��i�N�A�@�X�F�@�D"+ HIG"�ï]�B�A��"NOR +"�C \n\n",me);
                           me->add("ap",-40);
                           new(__DIR__"food/jansufatre-fish")->move(ob);
                           break;
        case 75..76 :
        message_vision("$N�p�ߪ��B�z�M�Ʋz�A�@�X�F�@�D"+HIC"���V�s��"NOR +"�C \n\n",me);
                           me->add("ap",-50);
                           new(__DIR__"food/inyelongment-fish")->move(ob);
                           break; 
        case 81..90 :
        message_vision("$N�ܦ��@�ߪ��C�C���N�A�@�X�F�@�D"+HIM"���⭻��"NOR +"�C \n\n",me);
                           me->add("ap",-50);
                           new(__DIR__"food/wuces-fish")->move(ob);
                           break; 
        case 96..104 :
        message_vision("$N�i�{��H���p���A�@�X�F�@�D"+HIY"���t����"NOR +"�C \n\n",me);
                           me->add("ap",-60);
                           new(__DIR__"food/liusug-fish")->move(ob);
                           break;
        case 117 :
        message_vision("$N���X�����g��A�@�X�F�@�D"+HIR"�c�ʱK��"NOR +"�C \n\n",me);
                           me->add("ap",-70);
                           new(__DIR__"food/gontinmi-fish")->move(ob);
                           break;        default :  
        message_vision("$N���������¼��A�@�X�F���ѧ@�~�C \n\n",me);
                           me->add("ap",-20);
                           new(__DIR__"food/failfood")->move(ob);                           break;
        }
        ob->add_temp("make_food",-1);
        me->enable_player_cmds();
        me->delete_temp("is_busy/making");     
           for(i=0;i<sizeof(obs);i++)
                destruct(obs[i]);
                return 1;
     }
   else    
      { 
      message_vision("$N���������¼��A�@�X�F���ѧ@�~�C \n\n",me);
        new(__DIR__"food/failfood")->move(ob);
        me->add("ap",-20);
        ob->add_temp("make_food",-1);
        me->enable_player_cmds();
        me->delete_temp("is_busy/making");                   
        for(i=0;i<sizeof(obs);i++)
                destruct(obs[i]);
                return 1;
      }    

}


  














