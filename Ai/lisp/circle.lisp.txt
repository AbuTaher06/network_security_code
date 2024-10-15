(format t "Enter the radius: " )
(setq r (read))

(setq area (* pi r r))
(format t"Circle Area: ~,2f~%" area)