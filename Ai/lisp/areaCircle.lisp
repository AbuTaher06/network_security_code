(let((r(read))
    (area 0))
    (format t "Enter the radius: ")
    (setq area(* pi r r ))
    (format t "Area is : ~,2f~%" area))




(progn
  (format t "Enter the radius: ")  
  (let ((r (read))  
        (pi 3.14159)) 
    (format t "You entered the radius: ~a~%" r)  
    (let ((area (* pi r r)))  
      (format t "Area is : ~,2f~%" area)))  
  nil) 