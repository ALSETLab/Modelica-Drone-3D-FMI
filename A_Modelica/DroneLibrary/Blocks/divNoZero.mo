within DroneLibrary.Blocks;
function divNoZero
  "Division avoiding 0 by replacing b with eps if requried"
  extends Modelica.Icons.Function;

  // Public variables
  input Real a "Dividend";
  input Real b "Divisor";
  input Real eps=Modelica.Constants.small "Smallest value used for division";
  input Boolean considerSign=true "True: sign is considered in case of 'b' < 'eps'";
  output Real c "Quotient";

algorithm
  if abs(b) < abs(eps) then
    if considerSign then
      c := if b >= 0 then a/eps else a/(-eps);
    else
      c := a/eps;
    end if;
  else
    c := a/b;
  end if;

  annotation (
    derivative = divNoZero_der,
    smoothOrder(normallyConstant=eps) = 0,
    Documentation(info="<html>
      <p>This function computes <code>c=a/b</code>. It avoids divisions by zero by replacing <code>a</code>/<code>b</code>
        with <code>a</code>/<code>eps</code> or <code>a</code>/<code>-eps</code> if <code>-eps</code> &LT; <code>b</code>
        &LT; <code>eps</code>.
      </p>
      <p>The block <a href=\"modelica://DymolaModels.Blocks.Math.DivNoZero\">DivNoZero</a> from the <code>DymolaModels</code>
      library offers similar functionality for graphical modelling.</p>
      </html>"));
end divNoZero;
