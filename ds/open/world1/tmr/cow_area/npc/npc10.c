#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HBK "�t�¥���" NOR,({"dark cow","cow"}) );
  set("long","�o�O�@�����H�@�˥ΨⰦ�}�����������A���L�ئa��B���ۡA�ݰ_�ӫD�`���޲��C\n");
  set("race", "beast");
  set("unit","�Y");
  set("title",HBK "�շt�������" NOR);
  set("age", 80);
  set("level", 50);
  set("limbs", ({ "�Y��", "����","�ݳ�","�I��", "�}", "����"}) );
  set("verbs", ({ "bite","claw" }) );
  set("chat_chance",30);
  set("chat_msg", ({
        (: random_move :),
        }) );
  set("chat_combat_chance",30);
  set("chat_combat_msg", ({
        (: random_move :),
        }) );
     set("max_hp", 500000 + random(20) * 10000);
  setup();
  

  carry_object(__DIR__"obj/meat");
  if( random(100) < 70 )
        carry_object(__DIR__"obj/meat");
  if( random(100) < 30 )
        carry_object(__DIR__"obj/meat");
}

void heart_beat()
{
if( query("hp") < 1 ) {
     this_player()->remove_all_killer();
     die();
return;
}

// �԰������|����
add_block(2);
}

int filter(object inv)
{
        if( inv->query_autoload() ) // save eq
                return 0;
        if( inv->query_unique() )  // daily eq
                return 0;
         if( inv->id("undead_item") )  // doll item
                  return 0;
       if( inv->id("horse") )  // horse npc
                  return 0;
       if( inv->id("quest_ob") )  // notebook
               return 0;
       if( inv->id("mail_ob") )  // mail object
               return 0;
       if( inv->id("horse") )  // horse npc
                 return 0;
       if( inv->query("not_clone") )  // not cloneable
                 return 0;
        return 1;
}

        
void cloneEquip(object me) {
        object *inv;
        object item;
        string msg;

        inv = all_inventory(me);
        if( !sizeof(inv) ) return;
        inv = filter_array(inv, (:filter:) );
        // �L�y�᪺����ƶq�ܤ֭n��8��
        if( sizeof(inv) < 8 ) return;
        
                // ��o item
        item = new( base_name(inv[random(sizeof(inv))]) );
        if( !objectp(item) ) return;

        msg = sprintf(HBK+"�i�������j"NOR"%s(%s)�X�g�F�C[%s]\n"NOR,item->query("name"), item->query("id") ,ctime(time()));
        message("system", msg ,users());
        msg = sprintf(HIB "�i�t�ΡjClone: %s -> %s"HIB"(%s)\n"NOR, me->query("id"), item->query("name"), item->query("id") ,ctime(time()));
        message("channel:sys", msg ,users());
        item->move(this_object());
}
void getReward(object me) {
        string *items = ({
                "10_bar.c","10_bio.c","10_wit.c","10_sou.c","10_tec.c"
        });

    // 20% ���v��o 10% merits ���b
    if( random(100) < 20 )
        new("/open/enhance/" + items[random(5)])->move(this_object());
    
    // 10 % ���v�q���a���W�ƻs�@�� item
   if( random(100) < 10 )
        cloneEquip(me);
    
    // �Ȩ�1�I����
   me->add("war_art", 1);
   tell_object(me, HIW "�A�o�� 1 �I�Ԫ����N�C\n"NOR);
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
        
        getReward(ob);

   ::die();
   return;
}

