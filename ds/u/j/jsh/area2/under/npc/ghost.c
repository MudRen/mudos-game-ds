#include <ansi.h>
inherit NPC;
void create()
{
        set_name(GRN"�ʬr��"NOR, ({ "poison ghost","ghost" }) );
        set("long","�q�@���j�Ѷ]�X�Ӫ����ǡC\n");
        set("level",32+random(15));
        set("age",100+random(4)); 
        set("title",HIG"�r�r�r"NOR);
        set("combat_exp", 10000+random(1000)); 
        set("evil",-20);        setup();
}  
int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
   if(!me || !target) return 0;
    if(random(10)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance*10) > tdex+tcon)
    {
      message_vision("\n"
                    +HIW"$N���M�����@�G -____-+\n" NOR     
                    +HIG"��$n�ĥh�A�i�}�j�f�r�F�U�h..!!!\n"NOR 
                    +HIR"�ˤf�ߧY�G��A�o�X���....\n"NOR
                    ,me,target);
      target->receive_damage("hp",50+random(50), this_object()); 
      apply_condition("poison",50);      return 1; 
    }
void die() 
{
    object ob; 
    if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);

    if( !ob ) { 
        ::die();
        return;
    } 
    ob->add("popularity",1); 
    message_vision(HIW"$N�ܦ��@�}�������h�F�C\n"NOR, this_object() );
    ::die();
    return;
}

