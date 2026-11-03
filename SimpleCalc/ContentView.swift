import SwiftUI

struct ContentView: View {
    private let engine = CalculatorWrapper()

    @State private var display: String = "0"
    @State private var currentOp: String? = nil

    let buttonRows: [[String]] = [
        ["C", "±", "÷"],
        ["7", "8", "9", "×"],
        ["4", "5", "6", "-"],
        ["1", "2", "3", "+"],
        ["0", ".", "="]
    ]

    var body: some View {
        ZStack {
            Color.black.ignoresSafeArea()
            VStack(spacing: 12) {
                Spacer()
                HStack {
                    Spacer()
                    Text(display)
                        .font(.system(size: 64, weight: .light))
                        .foregroundColor(.white)
                        .lineLimit(1)
                        .minimumScaleFactor(0.4)
                        .padding(.horizontal)
                }

                ForEach(buttonRows, id: \.self) { row in
                    HStack(spacing: 12) {
                        ForEach(row, id: \.self) { label in
                            CalcButton(label: label, action: { tap(label) })
                        }
                    }
                }
            }
            .padding()
        }
    }

    func tap(_ label: String) {
        switch label {
        case "C":
            engine.clear()
            display = "0"
            currentOp = nil
        case "±":
            engine.negate()
            display = format(engine.displayValue())
        case "0","1","2","3","4","5","6","7","8","9":
            engine.inputDigit(Int(label)!)
            display = format(engine.displayValue())
        case ".":
            engine.inputDecimal()
            display = format(engine.displayValue())
        case "+","-":
            engine.setOperation(label)
            currentOp = label
        case "×":
            engine.setOperation("*")
            currentOp = label
        case "÷":
            engine.setOperation("/")
            currentOp = label
        case "=":
            let result = engine.compute()
            display = format(result)
            currentOp = nil
        default:
            break
        }
    }

    func format(_ value: Double) -> String {
        if value == value.rounded() && abs(value) < 1e15 {
            return String(format: "%.0f", value)
        }
        return String(value)
    }
}

struct CalcButton: View {
    let label: String
    let action: () -> Void

    var body: some View {
        Button(action: action) {
            Text(label)
                .font(.system(size: 28, weight: .medium))
                .frame(maxWidth: .infinity, minHeight: 70)
                .background(background)
                .foregroundColor(.white)
                .clipShape(RoundedRectangle(cornerRadius: 20))
        }
    }

    var background: Color {
        switch label {
        case "÷","×","-","+","=":
            return .orange
        case "C","±":
            return Color(white: 0.65)
        default:
            return Color(white: 0.2)
        }
    }
}

#Preview {
    ContentView()
}
