#include <ansi2.h>
inherit ITEM;
mapping color = ([
// ---- �I���� -----
"$HBWHT$" : HBWHT,
"$BBLK$"  : NOR+BBLK,
"$HBRED$" : HBRED,
"$BRED$"  : NOR+BRED,
"$HBGRN$" : HBGRN,
"$BGRN$"  : NOR+BGRN,
"$HBYEL$" : HBYEL,
"$BYEL$"  : NOR+BYEL,
"$HBBLU$" : HBBLU,
"$BBLU$"  : NOR+BBLU,
"$HBMAG$" : HBMAG,
"$BMAG$"  : NOR+BMAG,
"$HBCYN$" : HBCYN,
"$BCYN$"  : NOR+BCYN,
"$BLINK$" : BLINK,

// ---- �e���� -----
"$BLK$" : HIW+BLK,
"$WHT$" : NOR+WHT,
"$HIW$" : HIW,
"$RED$" : RED,
"$HIR$" : HIR,
"$GRN$" : GRN,
"$HIG$" : HIG,
"$YEL$" : YEL,
"$HIY$" : HIY,
"$BLU$" : BLU,
"$HIB$" : HIB,
"$MAG$" : MAG,
"$HIM$" : HIM,
"$CYN$" : CYN,
"$HIC$" : HIC,
"$NOR$" : NOR
]);
void create()
{    
   set_name(HIY"��"+HIW"��"+HIR"��"+HIM"�z"NOR,({ "megaphone","msg" }));
   if( clonep() )
         set_default_object(__FILE__);
   set_weight(1);
   set("no_drop",1);
   set("can_give",1);
   set("no_sell",1);
   set("unit", "�x");
   setup();
}
int query_autoload() { return 1;}

void init()
{
    if(this_player()->query("id") == "fedex" || this_player()->query("env/wizard_open"))
    {
      add_action("do_message","msg");
      add_action("do_shot","shot");
      add_action("do_get","gett");
      add_action("do_color","color");
      this_player()->set_temp("invis",(int)SECURITY_D->get_wiz_level(this_player()));
      this_player()->set_temp("define_look",NOR" �����b�o�� "HIG"<�_�u��>"NOR);
      this_object()->set("long",
      "����������������������������������\n"
      "��"HIY"shot"NOR"  (�ߧY���`)              ��\n"
      "��"HIY"gett"NOR"  (�����e�������Y�˪��~)  ��\n"
      "��"HIY"msg"NOR"   (�N�W�D����r�[�W��X)  ��\n"
      "��"HIY"color"NOR" (��X�C��)              ��\n"
      "����������������������������������\n");
    }
    else { set("long",HIR"��z�P������"HIW+BLK"[�������M��]"NOR); }
}

int do_message(string arg)
{
    int i;
    object me = this_player();
    string msg,channels;
    string *source_color;
    string *target_color;

    if( !arg || sscanf(arg, "%s %s",channels,msg) != 2 )
      { return notify_fail(HIW+BLK"[�榡]: "HIR"msg <�W�D> <���e>\n"HIW+BLK"[�W�D]: ["HIR"say�Bemote�Bpast"HIW+BLK"]\n"NOR); }

    source_color = keys(color);
    target_color = values(color);
    for( i=0;i<sizeof(source_color);i++ )
       msg = replace_string(msg, source_color[i], target_color[i]);

    if( channels == "say" || channels == "'")
    {
       message_vision(YEL"$N���R"+msg+NOR"\n",me);
       return 1;
    }
    else if( channels == "emote")
    {
       message_vision(YEL+msg+NOR"\n",me);
       return 1;
    }
    else if( channels == "past" )
    {
       message("world:world1:vision","\n\t"+msg+NOR"\n\n",users());
       return 1;
    }
    else
    { return notify_fail(HIW+BLK"�Шϥ��W�D: ["HIR"say�Bemote�Bpast"HIW+BLK"]\n"NOR); }
 return 1;
}

int do_shot(string arg)
{
    int val=0;
    object *list,who,ob,me;
    me = this_player();
    ob = this_object();
    list = all_inventory(environment(me));
    if(!arg)
       return notify_fail(HIW+BLK"[�榡]: "HIR"shot <�Y�H> || <all>\n"NOR); 
    if(arg == "all")
    {
       foreach(object user in list)
         { if(living(user) && user != me) val++; }
       if(val<1)
         return notify_fail("�o�̥u���A�@�ӤH...\n");
       foreach(object user in list)
       {
          if(!living(user) || userp(user)) continue;
          tell_room(environment(me),HIC+user->name()+"��Mı���n�N�C\n"NOR);
          user->set_temp("temp/death_type",HIR"[�Q"+me->name(1)+"����]"NOR); 
          user->die();
       }
       return 1;
    }    
    if(!(who = present(arg, environment(me))) || !who->is_character() || who->is_corpse() )
       return notify_fail("�o�̨S���o�ӤH�C\n");
    if(arg == "fedex")
       return notify_fail("�A�L�k��"+who->name(1)+"�U�o�ӫ��O�C\n");
    tell_room(environment(who),HIC+(string)who->query("name")+"�Ө�����ߤ����d�h�۱��F�C\n"NOR);
    tell_object(who,HIW+BLK"[�A�۱��F]�C"NOR);
    who->delete("env/immortal");
    who->set_temp("temp/death_type",HIR"[�۱����`]"NOR); 
    who->die();  
    return 1;
}

int do_get(string arg)
{
    int i;
    object me,item,who;
    string obj,user;
    me = this_player();

    if(!arg || sscanf(arg, "%s from %s",obj,user) != 2)
       return notify_fail(HIW+BLK"[�榡]:"HIR" gett <�Y��> from <�Y�H>\n"NOR);
    if(!(who = present(user, environment(me))) )
       return notify_fail("�A�䤣�� "+user+" �o�˪F��C\n");
    if(who->query("id") == "fedex")
       return notify_fail(who->name(1)+"�^�Y���F�A�@���C\n");
    if(obj == "all")
    {
        if(sizeof(all_inventory(who))<1)
           return notify_fail(who->name()+"���W�S������F��C\n");
        foreach(object ob in all_inventory(who))
        {
       message_vision("$N�q$n���W�j�X�@"+item->query("unit")+item->name(1)+"�C\n",me,who);
           ob->move(me);           
        }
        return 1;
    }
    if(!item = (present(obj,who)))
       return notify_fail(who->query("name")+"���W�èS��"+obj+"�o��F��\n");
    message_vision("$N�q$n���W�j�X�@"+item->query("unit")+item->name(1)+"�C\n",me,who);
    item->move(me);
    return 1;
}

int do_color()
{
    write("
����X��Ӫ�
������������������������������������
���e����                          ��
��$RED$ - "RED"�`����"NOR"    $HIR$ - "HIR"�G����"NOR"��
��$GRN$ - "GRN"�`���"NOR"    $HIG$ - "HIG"�G���"NOR"��
��$YEL$ - "YEL"�g����"NOR"    $HIY$ - "HIY"�G����"NOR"��
��$BLU$ - "BLU"�`�Ŧ�"NOR"    $HIB$ - "HIB"�G�Ŧ�"NOR"��
��$MAG$ - "MAG"�t����"NOR"    $HIM$ - "HIM"������"NOR"��
��$CYN$ - "CYN"�ź��"NOR"    $HIC$ - "HIC"�ѫC��"NOR"��
��$BLK$ - "HIW+BLK"�L�Ǧ�"NOR"    $HIW$ - "HIW"�G�զ�"NOR"��
��                                ��
���I����                          ��
��$HBRED$ - "HBRED"�`����"NOR"                ��
��$HBGRN$ - "HBGRN"�`���"NOR"                ��
��$HBYEL$ - "HBYEL"�g����"NOR"                ��
��$HBBLU$ - "HBBLU"�`�Ŧ�"NOR"                ��
��$HBMAG$ - "HBMAG"�t����"NOR"                ��
��$HBCYN$ - "HBCYN"�ź��"NOR"                ��
��$BLINK$ - "BLINK"�{�{"NOR"                  ��
������������������������������������\n");
return 1;
}
