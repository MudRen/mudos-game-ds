void die()
{
         object ob,obj;
         if( random(100) > 70 ) {
                ::die();
                return;
        }
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }  

        // ����
        obj = new( query("skin") );
        if(objectp(obj))
                obj->move( this_object() ); 
        // �F�~�۾� quest
        if( ob->getToDo("/open/quest/hasake_bag.c") 
        && random(100) > 70) {
                obj = new( __DIR__"obj/stone" + (1+random(3)) );
                obj->move(this_object());
        }
      ::die();
      return;
}

