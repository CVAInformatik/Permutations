#print_depth 20;;
       
       
(*  from stackoverflow *)       
let distribute c l =
  let rec insert acc1 acc2 = function
    | [] -> acc2
    | hd::tl ->
      insert (hd::acc1) ((List.rev_append acc1 (hd::c::tl)) :: acc2) tl
  in 
  insert [] [c::l] l

let rec permutation = function
  | [] -> [[]]
  | hd::tl -> 
    List.fold_left (fun acc x -> List.rev_append (distribute hd x) acc) [] (permutation tl)
    
    
(*   insert a at pos in l  *)
let rec 
      insertAux a pos l acc =  if (pos = 0) then (( List.rev acc) @ a::l )
                                            else insertAux a (pos -1) (List.tl l)  ((List.hd l )::acc)
   and
			insert a pos l =  if( pos = 0) then a::l  else insertAux a  pos  l [];;
      
let rec permuteAux   li n   acc =
      match li with 
      |  [] -> acc
      | hd::tl  -> 
      let  p = (List.length acc) 
           in let pos = ( n mod (p+1))
           in let n1 = (n / (p+1)) 
           in permuteAux tl n1 (insert hd pos acc)
    and  
      permute li n =
      match li with 
      | []  -> []         (* empty list*)
      | hd::[] ->  [hd]   (* one element *)
      | hd::tl ->  permuteAux tl n [hd] (* more than one element list*)


let permutations li s = List.map (fun x -> permute li x  ) (List.init s (fun x -> x) );;
      
                   
let list_to_int lst = lst |> List.map string_of_int |> String.concat " " 

let rec iter  n x  = 
        let () =  Printf.printf "  %s  \n"  (list_to_int (permute n x ) )  
        in
        if (x = 0) then print_newline() else iter n (x-1)  ;;
        
let explode_string s = List.init (String.length s) (String.get s);;

let implode_char_list l = String.of_seq (List.to_seq l);;

